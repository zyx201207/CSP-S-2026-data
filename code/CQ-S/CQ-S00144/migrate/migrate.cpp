#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int u;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			u=a[i]-a[i-1];
		}
		int h=k/u;
		int g=n%h,s=n/h;
		cout<<s*g<<endl;
	}
	return 0;
}
