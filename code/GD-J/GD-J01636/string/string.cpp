#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
ll n,ans;
struct node{
	ll x;
	char c;
}a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	for(ll l=1,r=n;l<=r;){
		if(a[l].c!=a[r].c){
			ans+=min(a[l].x,a[r].x);
		}
		if(a[l].x<a[r].x){
			a[r].x-=a[l].x;
			l++;
		}
		else{
			a[l].x-=a[r].x;
			r--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
