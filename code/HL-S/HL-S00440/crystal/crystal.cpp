#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll N=5e5+100;
ll n,m;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll c=sum%n;
	ll ans=0;
	
	for(int i=0;i<n;i++){
		ll d=a[i];
		if(m>0){
			if(d<c){
				m-=c-d;
				ans++;
			}
		}
		if(d==c){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}