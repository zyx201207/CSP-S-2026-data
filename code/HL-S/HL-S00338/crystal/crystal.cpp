#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=5e5+5;
i128 a[N],s[N],m;
void Cmax(int &x,int y){ x=max(x,y);}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,x;
	cin>>n>>x;
	m=x;
	for(int i=1;i<=n;i++) {
		ll x; scanf("%lld",&x);
		a[i]=x;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])>m) l=mid+1;
			else r=mid;
		}
		Cmax(ans,(i-r+1));
	}
	cout<<ans;
	return 0;
}
