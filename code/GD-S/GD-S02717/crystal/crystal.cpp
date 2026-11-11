#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+9;
ll a[N];
void solved(){
	ll n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[2]-a[1]==a[3]-a[2]){
		ll x=a[2]-a[1];
		ll sum=0;
		for(ll i=x;i<=(n-1)*x;i+=x){
			sum+=i;
			if(sum==m){
				cout<<(i+x)/x;
				return ;
			}
			if(sum>m){
				cout<<i/x;
				return ;
			}
		}
		cout<<n;
		return ;
	}
	sort(a+1,a+n+1);
	ll mid=(n+1)/2;
	ll sum=0;
	ll x=0;
	for(ll i=mid+1;i<=n;i++){
		if(a[i]==a[mid]) x++;
		else break;
	}
	for(int i=1;i<=n;i++){
		sum+=abs(a[i]-a[mid]);
		if(sum>m){
			cout<<i-1;
			return ;
		}
		if(sum==m){
			if(i==mid-1) cout<<mid+x;
			else cout<<i;
			return ;
		}
	}
	cout<<n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	int t; cin>>t; while(t--)
	solved();
	return 0;
}
