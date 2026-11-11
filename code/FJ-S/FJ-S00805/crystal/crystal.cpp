#include <bits/stdc++.h>//[60-?]
using namespace std;
const int N=5e5+10;
typedef  unsigned long long ull;
typedef  long long ll;
ll a[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll p=1;
	for(int i=2;i<=n;++i){
		ll cf=a[i]-a[i-1],delta=(i-p)*cf;
//		cout<<"mΪ"<<m<<'\n';
		if(m-delta>=0){
			m-=delta;
		}
		else{
//			cout<<cnt<<endl;
			while(m-delta<0){
				m=m+(a[i]-a[p]);p++;
			}
			m-=delta;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<'\n';
	return 0;
}
