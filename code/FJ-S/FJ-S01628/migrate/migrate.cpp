#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		long long d,a[2000010];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d>=(a[n]-a[1])||d>((n/2)*(a[2]-a[1]))||d<=a[2]-a[1]){
			cout<<0<<endl;
			continue;
		}
		cout<<n-3<<endl;
	}
	return 0;
}
