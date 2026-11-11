#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll sum;
bool vis=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) vis=false;
	}
	if(vis){
		ll p=1;
		ll q=a[2]-a[1];
		while(m>=0){
			m-=p*q;
			p++;
		}
		if(p==1) cout<<1;
		else cout<<p-1;
		return 0;
	}
	ll k=1;
	ll it=2;
	while(m>=0&&it<=n+1){
		ll c=a[it]-a[it-1];
		//cout<<it<<" ";
		//cout<<c<<" ";
		m-=c*k;
		//cout<<c*k<<" ";
		//cout<<m<<" ";
		k++;
		//cout<<k<<" ";
		it++;
		//cout<<endl;
	}
	if(k!=1) k-=1;
	cout<<k;
	return 0;
}

