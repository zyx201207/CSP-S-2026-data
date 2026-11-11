#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll v[(int)1e6+5];
ll s[(int)1e6+5];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=(i-1)*(v[i]-v[i-1])+s[i-1];
	}
	for(ll i=2;i<=n;i++){
		if(m<s[i]){
			cout<<i-1<<endl;
			break;
		}
	}

	
	return 0;
}

