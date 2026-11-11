#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,x[2000005];
int dist[305][305]; 
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dist,0x3f3f3f3f,sizeof(dist));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(c<=6){
				for(int j=i-1;j>=1;j--){
					if(x[i]-x[j]<=d){
						dist[i][j]=dist[j][i]=1;
					}
				}
			}
		}
		if(c<=6){
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(dist[i][k]+dist[k][j]<dist[i][j]){
							dist[i][j]=dist[i][k]+dist[k][j];
						}
					}
				}
			}
			int res=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int sb=0;
					for(int k=i+1;k<j;k++){
						if(dist[i][j]==dist[i][k]+dist[k][j]){
							sb++;
						}
					}
					if(sb==2)res++;
				}
			}
			cout<<res<<"\n";
		}
	}
	return 0;
	
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
