#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,x[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		cout<<n/d;
	}
	return 0;
}
