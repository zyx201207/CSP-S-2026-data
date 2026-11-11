#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500100;
ll a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m,n;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,maxn=0,cnt=0;
	for(ll i=1;i<=n;i++){
		if(m>=(i-1)*a[i]-cnt){
			maxn=max(maxn,i-l+1);
		}
		else{
			bool op=0;
			for(ll j=l;j<=i-1;j++){
				if(m>=(i-j)*a[i]-cnt){
					l=j+1;
					op=1;
					break;
				}
				cnt-=a[j];
			}
			if(op==0) l=i;
		}
		cnt+=a[i];
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}

