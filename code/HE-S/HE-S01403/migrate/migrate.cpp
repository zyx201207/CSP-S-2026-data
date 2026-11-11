#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
long long n,d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,flag=0;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					continue;
				}
				else flag=1;
			}
		}
		if(flag==0){
			cout<<0<<endl;
		}
		long long g=a[2]-a[1];
		if(d<g*2){
			cout<<0<<endl;
		}
		else if(d>g&&d<a[n]-a[1]){
		  long long z=2*d;
		  ans=ans+n-z+1;
		  cout<<ans<<endl;
		}
	}
	return 0;
}
