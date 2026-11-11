#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],b[2000005],c,t,ans,bb;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>m){
				b[i+1]=1;
			}
		}
		for(int i=1;i<n-2;i++){
			for(int j=i+3;j<=n;j++){
				bb=0;
				for(int k=i;k<=j;k++){
					if(b[k]==1){
						bb++;
					}
				}
				if(j-i-1==2&&bb==0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
		
	return 0;
}
