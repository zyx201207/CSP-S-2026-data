#include <bits/stdc++.h>
using namespace std;

int a[2000000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans=0;
	cin>>c>>t; 
	for(int i = 0;i<t;i++) {
		cin>>n>>d;
		for(int j = 0;j<n;j++){
			cin>>a[j];
		}
		if(n<=d || d <= a[1]-a[0]){//²¿·Ö·Ö 
			cout<<0<<endl;
		}
		else {
			for(int k = 0;k<n-d;k++){
				ans+=n-d-k;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

