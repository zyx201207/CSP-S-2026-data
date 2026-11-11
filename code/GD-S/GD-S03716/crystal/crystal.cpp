#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
const ll inf=0x3f3f3f3f;
ll n,m,a[maxn],b[maxn],s[10000][10000],maxx=-inf;
bool f=true,ff=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=false;
		b[i]=a[i]-a[i-1];
	}
	for(ll i=2;i<=n;i++){
		if(b[i]!=b[i-1])ff=false;
	}
	if(f||ff){
		ll o=0,p=0,q=1;
		for(ll i=1;i<=n;i++)o+=a[n]-a[i];
		if(m==0)cout<<1;
		else if(m>=o)cout<<n;
		else{
			for(ll i=n-1;i>=1;i--){
				p+=a[n]-a[i];
				if(m>=p)q++;
			}
			cout<<q;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(a[j]>=a[i])continue;
			s[i][j]=a[i]-a[j];
		}
	}
	for(ll i=n;i>=1;i--){
		ll ans=0,cnt=1;
		for(ll j=i-1;j>=1;j--){
			ans+=s[i][j];
			if(m>=ans)cnt++;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
