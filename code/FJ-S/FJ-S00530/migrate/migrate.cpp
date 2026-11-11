#include<bits/stdc++.h> 
using namespace std;
int c,t;
long long n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[i]>d){
					long long t=0;
					for(int k=i+1;k<j;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
							t++;
						}
					}
					if(t==2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
