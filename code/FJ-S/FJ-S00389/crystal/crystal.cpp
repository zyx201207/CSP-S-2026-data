#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500010;
ll n,m,a[N],c[N],s[N],ans=1,tmp,C,f=1,mm,p[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	C=a[2]-a[1];
	for(ll i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]!=C){
			f=0;
		}
	}
	if(f==1){
		mm=m;
		for(ll i=2;i<=n;i++){
			if(c[i]*(i-1)<=mm){
				mm-=c[i]*(i-1);
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+c[i];
	}
	for(ll i=2;i<=n;i++){
		tmp=1,mm=m;
		for(ll j=i;j>=2;j--){
			if(s[i]-s[j-1]<=mm){
				tmp++;
				mm-=s[i]-s[j-1];
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
