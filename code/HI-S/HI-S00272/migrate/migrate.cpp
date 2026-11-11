#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		if (n<=3){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)cin>>a[i];
		bool p=1;int sum=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if (a[i]-a[i-1]!=sum){
				p=0;
				break;
			}
		}	
		if (p==1){
			cout<<n/2<<endl;
		}
	}
	return 0;
}
