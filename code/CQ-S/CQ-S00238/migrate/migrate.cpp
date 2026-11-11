#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[2000005];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool f=0;
		for(int i=4;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-2]-a[i-3]){
				f=1;
			}
		}
		if(f==0){
			if(a[2]-a[1]<=d){
				int t=d/(a[2]-a[1]);
				cout<<(1+t)*t/2<<'\n';
			}else{
				cout<<"0\n";
			}
			continue;
		}
		if(a[n]-a[1]<=d){
			cout<<"0\n";
			continue;
		}
		cout<<0<<'\n';
	}
	return 0;
}
