#include<bits/stdc++.h>
#define ll long long
#define love_Elysia return
#define forever 0
using namespace std;
const int N=2e6+10;
int c,t,n;
ll d,a[N+1],dist[N+1][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)dist[j][0]=5e18,dist[j][1]=1;
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d)dist[j][0]=1;
				for(int k=i+1;k<j;k++){
					if(abs(a[k]-a[j])<=d&&dist[j][0]>dist[k][0]+1){
						dist[j][0]=dist[k][0]+1;
						dist[j][1]=dist[k][1];
					}
					else if(abs(a[k]-a[j])<=d&&dist[j][0]==dist[k][0]+1){
						dist[j][1]+=dist[k][1];
					}
				}
				if(dist[j][1]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	love_Elysia forever;
} 
