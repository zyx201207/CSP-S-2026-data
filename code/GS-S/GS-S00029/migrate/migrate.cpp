#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long a[200005],n,d,ans,anss;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int f=1;
			for(int j=i+1;j<=n;j++){
				if(abs(a[j]-a[i])>d){
					f=0;
					break;
				}
			}
			if(f){
				anss=a[i];
				break; 
			}
		}
		for(int i=1;i<=n;i++){
			if(abs(a[i]-a[i+1])<=d&&a[i]!=anss&&a[i+1]!=anss){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
