#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;
const int N=5e5+10;
ll a[N],s1[N],x[N];//s下标2~n 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//特殊性质A B 
	if(n>5000){
		ll ans1=0;
		ll k1=abs(a[2]-a[1]);
		for(ll i=k1;;i+=k1){
			if(ans1+i<=m){
				ans1+=i;
			}
			else cout<<ans1<<endl;
		}
		return 0;
	}
	for(int i=2;i<=n;i++){
		ll x1=a[i]-a[i-1];
		x[i]=x[i-1]+x1;
		s1[i]=s1[i-1]+(i-1)*x1;
	}
	ll ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll x1=s1[j]-x[i];
			ll j1=j+1-i;
			if(x1<=m){
				ans=max(ans,j1);
			}
			else break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
