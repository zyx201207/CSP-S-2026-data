#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll n,len,ans,a[200010],s[200010][26],lens[200010];
char c[200010];
ll query(ll x,char ch){
	ll l=1,r=n,anss=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(lens[mid]<=x) anss=mid,l=mid+1;
		else r=mid-1;
	}
	ll cnt=s[anss][ch-'a'];
	if(anss<n && c[anss+1]==ch){
		if(x<=lens[anss+1]) cnt+=(x-lens[anss]);
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	rep(i,1,n){
		cin >> a[i] >> c[i];
		rep(j,0,25) s[i][j]=s[i-1][j];
		s[i][c[i]-'a']+=a[i];
		lens[i]=lens[i-1]+a[i];
		len+=a[i];
	}
	ans=len;
	rep(i,1,n){
		//[1,n-s[i-1]]-[1,n-s[i]]
		ans-=(query(len-lens[i-1],c[i])-query(len-lens[i],c[i]));
	}
	cout << ans/2;
	return 0;
}
