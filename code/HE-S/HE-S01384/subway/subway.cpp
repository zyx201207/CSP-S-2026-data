#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long a[60000];
vector<long long>zhan[6000000];
long long tt[60000][500];
long long x[60000];
long long aa[60000];

bool vis[6000000];

vector<pair<long long,long long> >vec[60000];

struct node{
	long long x,t,zh;
};
queue<node>qq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)  cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			int tim;
			cin>>aa[j]>>tim;
			tt[aa[j]][i]=tim;
			zhan[aa[j]].push_back(i);
			if(j>1){
				vec[aa[j-1]].push_back(make_pair(aa[j],i));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		if(st==ed){
			printf("0");
			continue;
		}
		qq.push((node){st,a[st],-1});
		vis[st]=1;
		while(!qq.empty()){
			node tp=qq.front();
			qq.pop();
//			cout<<tp.x<<" "<<tp.t<<" "<<tp.zh<<"\n";
			if(tp.x==ed){
				long long tim=1e18;
				for(int i=0;i<vec[tp.x].size();i++){
					long long ii=vec[tp.x][i].first;
					tim=min(tim,tp.t+tt[tp.x][ii]);
				}
				printf("%lld\n",tim);
				break;
			}
			for(int i=0;i<vec[tp.x].size();i++){
				int xx=vec[tp.x][i].first,yy=vec[tp.x][i].second;
//				cout<<xx<<" "<<yy<<"\n";
				if(!vis[xx]){
					vis[xx]=1;
					int tim=tp.t+tt[tp.x][i+1];
//					cout<<tim<<" "<<yy<<"\n";
					qq.push((node){xx,tim+tt[xx][yy],yy});
				}
			}
		}
		memset(vis,0,sizeof(vis));
		while(!qq.empty())  qq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
