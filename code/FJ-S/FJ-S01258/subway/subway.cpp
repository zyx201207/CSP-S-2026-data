#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;//M是地铁站数,N是地铁线数 
long long w[M];
vector<int>a[N],t[N],train[M];
bool vis[M];
long long ans;
void dfs(int x,long long time,int y){
	if(x==y){
		ans=min(ans,time);
		return;
	}
	for(int i=0;i<train[x].size();i++){//经过的铁路 
		int tr=train[x][i];//当前铁路 
		for(int j=0;j<a[tr].size();j++){//可到达的车站 
			int sta=a[tr][j];//当前站点 
			if(vis[sta])continue;
			vis[sta]=1;
			int pos;
			for(int k=0;k<a[tr].size();k++){
				if(a[tr][k]==x){
					pos=k;
					break;
				}
			}
			dfs(sta,time+t[tr][pos]+t[tr][j],y);
			vis[sta]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int ta,tt;
			cin>>ta>>tt;
			a[i].push_back(ta);
			t[i].push_back(tt);
			train[ta].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=1e18;
		vis[x]=1;
		dfs(x,w[x]+w[y],y);
		vis[x]=0;
		cout<<ans<<endl;
	}
	return 0;
} 
