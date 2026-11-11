#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4007;
int C,t;
int n,dp;
int a[N],res=0;
int d[N][N],c[N][N];
vector<int>g[N];

struct Node{
	int idx,step;
	Node(){
		idx=0,step=0;
	}
	Node(int _idx,int _step){
		idx=_idx,step=_step;
	}
};


signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>dp;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=dp)g[j].push_back(i);
				else break;
			}
		}
		memset(d,0x3f,sizeof(d));
		memset(c,0,sizeof(c));
		res=0;
		for(int i=1;i<=n;i++){
			queue<Node>q;
			q.push({i,0});
			while(q.size()){
				auto tmp=q.front();
				int x=tmp.idx,step=tmp.step;
				q.pop();
				for(auto e:g[x]){
					if(d[i][e]>step+1){
						d[i][e]=step+1;
						c[i][e]=1;
//						q.push({e,step+1});
					}else if(d[i][e]==step+1){
						c[i][e]++;
					}
					q.push({e,step+1});
				}
			}
			for(int j=i+1;j<=n;j++){
				if(c[i][j]==2){
					res++;
//					cout<<i<<' '<<j<<'\n';
				} 
			}
		} 
		cout<<res<<'\n';
	}
	return 0;
}
