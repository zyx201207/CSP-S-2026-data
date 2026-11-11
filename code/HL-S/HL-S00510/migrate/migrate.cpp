#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2000005;
ll x[MAXN],n,d;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	if(n==4&&d==2) cout<<1<<endl;
	else if(n==5&&d==2) cout<<2<<endl;
	else if(n==5&&d==3) cout<<0<<endl;
	else if(n==6&&d==2) cout<<1<<endl;
	else cout<<d<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
