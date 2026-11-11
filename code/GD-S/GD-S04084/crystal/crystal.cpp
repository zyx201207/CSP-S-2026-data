#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 5e5+5;
ll n,m,ans=0,Max=INT_MIN;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	//for(ll i=1;i<=n;i++) cout<<a[i]<<' ';
	//cout<<n<<' '<<m<<'\n';
	ll idx;
		for(ll i=1;i<=n;i++){
			if(m<0) break;
			if(a[i]<=a[i+1]&&m-abs(a[i+1]-a[i])>=0){
				m=m-((a[i+1]-a[i])*ans);
				ans++;
			}
		}
		cout<<ans;
		return 0;
}
