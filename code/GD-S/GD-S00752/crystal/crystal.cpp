#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e6;
ll a[N],c[N]={0},step=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0;
	for(ll i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		cout<<c[i];
	}
	step=c[1];
	for(ll i=2;i<=n;i++){
		ll t=c[i]+c[i-1];
		ll t1=t+c[i];
		ll j=i-1;
		ll s=0;
		while(j>=1){
			s+=t1;
			cout<<s<<" "<<t1<<" "<<i<<" "<<j<<" ";
			if(s>m) break;
			step=max(step,i);
			j--;
			t1+=c[i-j+1];
		}
	}
	cout<<endl<<step;
	return 0;
}
