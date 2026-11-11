#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[505],a[500005],t[500005],s1[505],s2[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		ll k; cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			s1[i]+=a[j]; s2[i]+=t[j];
		}
	}
	while(q--) {
		ll x,y; cin>>x>>y; ll sum=0;
		for(int i=x;i<y;i++) sum+=s2[i]; 
		cout<<w[x]+w[y]+sum<<"\n";
	}
} 
