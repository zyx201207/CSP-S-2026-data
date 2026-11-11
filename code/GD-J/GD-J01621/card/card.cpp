#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m;
ll a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
		if(m==1){
			cout<<n;
			return ;
		}
		if(n==m) {
			for(int i=1;i<=n;i++) cout<<i<<" ";
		}
		if(m==2){
			cout<<n<<" "<<n-1;
			return ;
		}
		else{
			for(int i=1;i<=n;i++) cout<<i<<" ";
		}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
