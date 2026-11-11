#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string st;
ll c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,m,a[1000006];
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<n%m;
	}
	return 0;
}

