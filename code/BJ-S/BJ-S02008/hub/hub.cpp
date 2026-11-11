#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,uu,vv;
vector<int>ve[1000005];
long long mindis=998244;
bool vis[1000050];
void dfs(long long d,long long fa,long long dis){
	//cout<<d<<"\n";
	if(vis[d]==1){
		mindis=min(mindis,dis);
		return;
	}
	for(int i=0;i<ve[d].size();i++){
		if(ve[d][i]==fa)continue;
		dfs(ve[d][i],d,dis+1);
	}
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)ve[i].clear();
		for(int i=1;i<n;i++){
			cin>>uu>>vv;
			ve[uu].push_back(vv);
			ve[vv].push_back(uu);
		}long long minn=999999;
		for(int i=0;i<(1<<n)-1;i++){
			int p=0,q=i;
			for(int ii=1;ii<=n;ii++){
				vis[ii]=0;
			}
			while(q>0){
				//vis[q&-q]=1;
				q-=(q&-q);
				p++;
			}q=i;
			int down=0;
			for(int j=1;j<=(1<<(n-1));j*=2){
				down++;
				vis[down]=q&j;
				//cout<<vis[down]<<" ";
			}//cout<<"\n";
			if(p!=k)continue;
			long long maxx=0;
			for(int j=1;j<=n;j++){
				mindis=998244;
				dfs(j,0,0);
				maxx=max(maxx,mindis);
			}
			minn=min(minn,maxx);
		}
		cout<<minn<<"\n";
		
		//cout<<"1\n";
	}
	return 0;
}
