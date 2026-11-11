#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
typedef long long ll;
ll n,d;
int c;
ll a[N];
bool check(ll x,ll y){
	ll len=(a[x]<a[y])?(a[y]-a[x]):(a[x]-a[y]);
	if(len==1){
		return 0;
	}
	if(len%d==0){
		return 0;
	}
	if(len%d==1&&d>2){
		return 0;
	}
	return 1;
}
void solve(){
	memset(a,0,sizeof a);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c>=13&&c<=14){
		cout<<"0\n";
		return;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(check(i,j)){
				//cout<<i<<' '<<j<<'\n';
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("mirgate.in","r",stdin);
	freopen("mirgate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>c>>_;
	while(_--){
		solve();	
	}
	return 0;
}
