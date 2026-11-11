#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void dyr(){
	int c,_;
	cin>>c>>_;
	while(_--){
		int n;
		ll d;
		cin>>n>>d;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int mx=a[2]-a[1];
		mx=d/mx;
		cout<<n-(2*mx-1)<<endl; 
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
