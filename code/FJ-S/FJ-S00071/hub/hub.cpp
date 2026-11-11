#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 i8;
const ll N=1e5+7,inf=(1ll<<60),mod=1e9+7;
using namespace std;
ll c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			ll tmp;
			cin>>tmp>>tmp;
		}
		if(k==n)cout<<"0\n";
		else if(k>=n/2)cout<<"1\n";
		else cout<<(n/2-k+3)/4<<endl;
	}
}

