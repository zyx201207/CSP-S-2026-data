#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+5;
int n;
pair<ll,char> a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	ll ans=0;
	int l=1,r=n;
	while(l<r){
		ll x=min(a[l].first,a[r].first);
		if(a[l].second!=a[r].second){
			ans+=0LL+x;
		}
		a[l].first-=x;
		a[r].first-=x;
		if(!a[l].first){
			l++;
		}
		if(!a[r].first){
			r--;
		}
	}
	cout<<ans;
	return 0;
}