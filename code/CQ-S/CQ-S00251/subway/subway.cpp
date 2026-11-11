#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=5e2+5,INF=0x3f3f3f3f3f3f3f3f;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void write(int x){
	if(!x){putchar('0');puts("");return;}
	if(x<0){putchar('-');x=-x;}
	char s[20];int n=0;
	while(x) s[n++]=char(x%10+'0'),x/=10;
	while(n--) putchar(s[n]);
	puts("");
}
int c,m,n,d,q,w[N],dis[M][M],tmp1[M],tmp2[M];
vector<pair<int,int> >path[N];
void input(){
	c=read(),m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=m;i++){
		int k;k=read();
		while(k--){
			int x,y;x=read(),y=read(); 
			path[x].emplace_back(i,y);
		}
	}
}
void build(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<path[i].size();j++){
			for(int k=j+1;k<path[i].size();k++){
				int tmp=path[i][j].second+path[i][k].second;
				int from=path[i][j].first,to=path[i][k].first;
				dis[from][to]=min(dis[from][to],tmp);
				dis[to][from]=min(dis[to][from],tmp);
			}
		}
	}
}
void floyd(){
	int t;
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				t=dis[i][k]+dis[k][j];
				if(dis[i][j]>t) dis[i][j]=t;
			}
		}
	}
}
void solve(){
	while(q--){
		int s,t,ans=INF;s=read(),t=read();
		for(int i=0;i<path[s].size();i++){
			for(int j=0;j<path[t].size();j++){
				int from=path[s][i].first,to=path[t][j].first;
				int w=path[s][i].second,ww=path[t][j].second;
				ans=min(ans,dis[from][to]+w+ww);
			}
		}
		write(ans+w[s]+w[t]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();build();floyd();solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
