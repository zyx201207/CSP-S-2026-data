#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[800005],b[400005];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]>d&&a[j]-a[j-2]<=d&&a[j]-a[j-3]>d){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

