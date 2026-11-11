#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n;
struct Let{ ll len; char c; }a[N];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].len>>a[i].c;
	ll L=0,R=0;
	for(int i=1,j=n;i<=j;){
		ll nl=L+a[i].len,nr=R+a[j].len;
		if(nl>nr){
			if(a[i].c!=a[j].c) ans+=a[j].len;
			a[i].len-=a[j].len; --j;
			L=nr,R=nr;
		} else if(nl<nr){
			if(a[i].c!=a[j].c) ans+=a[i].len;
			a[j].len-=a[i].len; ++i;
			L=nl,R=nl;
		} else if(nl==nr){
			if(a[i].c!=a[j].c) ans+=a[i].len;
			++i,--j;
			L=nl,R=nr;
		}
	} cout<<ans;
	return 0;
} 
