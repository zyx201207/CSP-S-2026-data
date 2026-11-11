#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
#define _for1(i,x,y,z) for(int i=x;i>=y;i-=z)
typedef long long ll;
void solve(){
	int n,k;
	cin>>n>>k;
	_for(i,1,n-1,1){
		int u,v;
		cin>>u>>v;
	}cout<<int(ceil(1.0*n/k))/2<<"\n";
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)solve();
}
