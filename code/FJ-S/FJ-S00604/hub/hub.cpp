#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
ll c,t,n,k; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ll a,b;
		FOR(i,1,n-1)cin>>a>>b;
		cout<<ceil(((n+1)/2-b)/3.0)<<"\n";
	}
	return 0;
}

