#include<bits/stdc++.h>
using namespace std;
int c,n,t;
long long d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=3;i<=n;i++){
			if(d>=a[i]-a[1]&&a[i+1]-a[1]>d){
				for(int j=a[n]-d;j>=a[1];j--){
					cnt+=min(a[n]-d-j,(d/(a[2]-a[1]))-1);
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
