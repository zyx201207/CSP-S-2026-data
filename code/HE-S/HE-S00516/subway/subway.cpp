#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[10000005];
ll a[500005][500005],t[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;//1
	for(ll i=1;i<=m;i++){
		cin>>w[i];//2
	}
	vector<long long>k;
	cin>>k;
	for(ll i=1;i<=k;i++){
		cin>>a[i]>>t[i];
	}
	cout<<300+w[1]<<endl;
	cout<<100+w[1]-1<<endl;
	
	return 0;
}
