#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
vector<long long> v,w;
int main(  ){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k;
		v.push_back(k);
	}
	for(int i=29;i>=0;i--){
		for(int j=0;j<v.size( );j++){
			if((1ll<<i)&v[j]){
				w.push_back(v[j]);
			}
		}
		if(w.size( )<m){
			w.clear( );
			continue;
		}
		ans+=(1ll<<i);
		v=w;
		w.clear( );
	}
	cout<<ans;
	return 0;
} 
