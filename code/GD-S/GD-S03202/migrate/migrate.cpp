#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d;
ll a[2000006];
set<ll> s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll num=d/(a[2]-a[1]);
		if(num==0){
			cout<<0<<'\n';	
			continue;
		}
		ll d1=(n-1)/num+1;
		ll res=(n-1)%num;
		ll del=((d1*(d1-1))/2)*(res+1);
		del+=(((d1-1)*(d1-2))/2)*(num-res-1);
		cout<<(n*(n-1))/2-del-n+1<<'\n';
	}
	return 0;
}
 
