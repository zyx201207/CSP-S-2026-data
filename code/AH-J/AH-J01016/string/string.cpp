#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
struct Node{
	ll m;
	char x;
}a[N];
ll n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].m>>a[i].x;
	ll l=1,r=n,ans=0;
	while(l<=r){
		if(a[l].x!=a[r].x) ans+=min(a[l].m,a[r].m);
		if(a[l].m<a[r].m){
			a[r].m-=a[l].m;
			l++;
		}
		else if(a[l].m>a[r].m){
			a[l].m-=a[r].m;
			r--;
		}
		else l++,r--;
	}
	cout<<ans;
	return 0;
}
