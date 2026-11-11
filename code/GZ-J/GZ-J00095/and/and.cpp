// GZ-J00095 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
using namespace std;
ll n,m,ans,f,fx,maxn,a[MAXN];
bool check(ll w){
	ll x=w;
	while(x){
		if((x%2)==1 && x!=1) return true;
		x/=2;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=n;i>=n-m+1;i--){
		if(!check(a[i])){
			m++;
			maxn=max(maxn,a[i]);
		}else{
			if(!f) ans=a[i],f=1;
			else ans&=a[i];
		}
		if(m>n){
			fx=1;
			break;
		}
	}
	if(fx==1){
		cout<<maxn;
		return 0;
	}
	cout<<ans;
	return 0;
}
