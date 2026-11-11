#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int maxn=512;
const int maxm=5e5+5;
int w[maxm];
int K[maxn];
vector<pair<int,pair<int,int> > > Path;//站点，地铁线，时间 
#define isdigit(x) (x<='9' && x>='0')
void read(int &n){
	n=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		n=n*10+c-48;
		c=getchar();
	}
}
void out(int n){
	if(n){
		out(n/10);
		putchar(n%10+'0');
	}
}


int length[maxn][maxn];//建的图 
int beg[maxm];
void readin(){
	read(c);
	read(n);
	read(m);
	read(d);
	read(q);
	for(int i=1;i<=m;++i){
		read(w[i]);
	}
	for(int i=1;i<=n;++i){
		read(K[i]);
		for(int j=1,a,t0;j<=K[i];++j){
			read(a);
			read(t0);
			Path.push_back(make_pair(a,make_pair(i,t0)));
		}
	}
}

void input_init(){
	//step0:初始化 
	memset(length,0x3f,sizeof(length));
	memset(beg,0x3f,sizeof(beg));
	for(int i=1;i<=n;++i){
		length[i][i]=0;
	}
	//step1:根据每个站点建图
	sort(Path.begin(),Path.end());
	int j;
	for(int i=0;i<Path.size();++i){
		beg[Path[i].first]=min(beg[Path[i].first],i);
		j=i+1;
		while(Path[j].first==Path[i].first){
			int from=Path[i].second.first;
			int to=Path[j].second.first;
			int cost=Path[i].second.second+Path[j].second.second;
			length[from][to]=min(length[from][to],cost);
			length[to][from]=min(length[from][to],cost);
			++j;
		}
	}
	beg[m+1]=Path.size();
	//step2:跑floyd算法
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				length[i][j]=min(length[i][j],length[i][k]+length[k][j]);
			}
		}
	}
}
void printout(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			out(length[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
}
void solve(){
	int x,y;
	read(x);
	read(y);
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=beg[x];i<beg[x+1];++i){
		for(int j=beg[y];j<beg[y+1];++j){
			if(ans>Path[i].second.second+Path[j].second.second+length[Path[i].second.first][Path[j].second.first]){
				ans=Path[i].second.second+Path[j].second.second+length[Path[i].second.first][Path[j].second.first];
			}
		}
	}
    out(ans+w[x]+w[y]);
	putchar('\n');
}



signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	readin();
	input_init();
//	printout();
	while(~--q){
		solve();
	}	
}
