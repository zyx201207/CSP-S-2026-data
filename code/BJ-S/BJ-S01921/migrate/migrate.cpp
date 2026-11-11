#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,f=1;
		ll d,mx=-1;
		cin>>n>>d;
		vector<ll> a(N);
		for(int x=1;x<=n;x++){
			cin>>a[x];
			if(a[x]-a[x-1]!=mx&&x>1) f=0;
			if(x!=1) mx=max(mx,a[x]-a[x-1]);
		}
		if(d<=mx||(f==1&&d<(mx*2))){
			cout<<0;
			continue;
		}
		cout<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

