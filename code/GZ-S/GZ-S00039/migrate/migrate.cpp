//GZ-S00039 贵阳市第一中学 吴昊然
#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=(a[j]-a[i])%(d/(a[2]-a[1]);
				if(x>=){
					ans+=(a[j]-a[i])/(d/(a[2]-a[1])+1;
				}		
			}
		}
		cout<<ans;
	}
	return 0;
} 
