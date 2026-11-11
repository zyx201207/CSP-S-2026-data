#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll c,t,a[2000050];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		ll n=0;
		ll d=0;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<(n-1)/2<<'\n';
	}
	
	
	return 0;
}
