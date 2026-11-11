#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500005],ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cnt=0,len=0;
	for(ll i=1;i<=n;i++){
		cnt+=len*(a[i]-a[i-1]);
		len++;
		while(cnt>m){
			len--;
			cnt-=a[i]-a[i-len];
		}
		ans=max(ans,len);
	}
	cout<<ans;
}
