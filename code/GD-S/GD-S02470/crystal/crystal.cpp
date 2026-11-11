#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],n,m,b[N],mn=11451419198101145,mnpos=1;
vector<ll> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			ll d=abs(a[i]-a[j]);
			b[i]+=d;
		}
		if(mn>b[i]){
			mn=b[i];
			mnpos=i;
		}
		for(int j=1;j<=n;j++) b[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(i==mnpos) continue;
		ll d=abs(a[i]-a[mnpos]);
		v.push_back(d);
	}
	sort(v.begin(),v.end());
	ll ans=0,st=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[mnpos]) st++;
	}
	ans=st;
	for(int i=0;i<v.size();i++){
		if(v[i]==0){
			continue;
		}
		if(m>=v[i]){
			ans++;
			m-=v[i];
		}
	}
	cout<<ans;
	return 0;
}
