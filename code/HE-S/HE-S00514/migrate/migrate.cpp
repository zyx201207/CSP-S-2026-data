#include<bits/stdc++.h>
using namespace std;
int c,t; 
const int N=5005;
int dist[N][N];
int ans;
int n;
int f[N][N];
void floid(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int z=dist[i][k]+dist[k][j];
				if(dist[i][j]==z){
					f[i][j]++;
				}
				if(dist[i][j]>z) dist[i][j]=z;
			}
		}
	}	
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		int d;
		cin>>n>>d;
		int a[N];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=0x3f3f3f3f;
			}
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[2]-a[1]>d){
			cout<<0;
			continue;
		}
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d){
					dist[i][j]=a[i]-a[j];
				}			
			}
		}
		
		ans=0;
		floid();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){  
				if(f[i][j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
