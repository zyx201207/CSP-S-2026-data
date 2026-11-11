#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,m,e=1;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while((1<<e)<a[i]) e++;
	}
	ll ans=0;
	for(ll i=e;i>=0;i--){
		int w=0;
		for(int j=1;j<=n;j++) if(((a[j]&ans)==ans)&&(a[j]&(1<<i))) w++;
		if(w>=m) ans+=((1LL)<<i);
	}
	cout<<ans;
	return 0;
}
