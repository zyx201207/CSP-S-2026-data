#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+3; 

int c,T;

int n,k;
int mp[1005][1005];

void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
			//cout<<i<<" "<<j<<" "<<mp[i][j]<<'\n';
		}
	} 
} 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			mp[u][v]=mp[v][u]=1;
		}
		floyd();
		
		
		vector<int>t;
		int mi=1e9;
		for(int mask=1;mask<(1<<(n+1));mask++){
			int tot=0;
			t.clear();
			for(int j=1;(1<<j)<=mask;j++)if((1<<j)&mask){
				tot++;
				t.push_back(j);
			}
			if(tot!=k)continue;
			int mx=-1;
			for(int u=1;u<=n;u++){
				int mii=1e9;
				for(int v:t){
					mii=min(mii,mp[u][v]);
				}
				//cout<<mii<<'\n';
				if(mii!=1e9)mx=max(mx,mii);
			}
			if(mx!=-1)mi=min(mi,mx);
		}
		cout<<mi<<'\n';
	}
	return 0;
} 
