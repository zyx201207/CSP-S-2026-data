#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[530053];vector<pair<int,long long> > v[530053];
long long disn[503][503];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			disn[i][j]=1e17;
			if(i==j)disn[i][j]=0;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++){
			int x;long long y;cin>>x>>y;
			v[x].push_back({m+i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto e:v[i]){
			for(auto ee:v[i]){
				disn[e.first-m][ee.first-m]=min(disn[e.first-m][ee.first-m],e.second+ee.second);
				disn[ee.first-m][e.first-m]=min(disn[ee.first-m][e.first-m],e.second+ee.second);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				disn[i][j]=min(disn[i][j],disn[i][k]+disn[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		long long ans=1e17;
		for(auto e:v[s]){
			for(auto ee:v[t]){
				ans=min(ans,e.second+ee.second+disn[e.first-m][ee.first-m]);
			}
		}
		cout<<ans+w[s]+w[t]<<"\n"; 
	}
	return 0;
} 
