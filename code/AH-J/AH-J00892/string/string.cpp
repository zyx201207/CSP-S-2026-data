#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5;
struct par{ll a;char c;}a[MAXN+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i].a>>a[i].c;
	ll l=0,r=n-1;
	while(l<r){
		if(a[l].a>a[r].a){
			if(a[l].c!=a[r].c)
				ans+=a[r].a;
			a[l].a-=a[r--].a;
		}else if(a[l].a<a[r].a){
			if(a[l].c!=a[r].c)
				ans+=a[l].a;
			a[r].a-=a[l++].a;
		}else{
			if(a[l].c!=a[r].c)
				ans+=a[l].a;
			l++; r--;
		}
	}cout<<ans;
	return 0;
}
