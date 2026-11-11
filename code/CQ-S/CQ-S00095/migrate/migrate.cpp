#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t,n,d,x[2000005];
struct node{
	int step,way;
	//int dis?
}a[2000005][2000005];//j:终点的下标 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=1;k<=i;k++){
				 
				if(x[j]-x[j-k]<=d) {
					a[i][j].step=min(a[i][j].step,a[i][j-1].step+1);
					a[i][j].way++;
				
				  	}
				} 
				
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i][j].way==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

