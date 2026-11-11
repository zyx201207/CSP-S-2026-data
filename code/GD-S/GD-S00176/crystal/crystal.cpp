#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ans;
ll a[N],s[N];

inline bool cmp(ll n1,ll n2){
	return n1>n2;
}
inline ll find(int x){
	int l=x,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(s[mid]-s[x-1]+m>=(mid-x+1)*a[x])
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int t=find(i);
		ans=max(ans,1ll*(t-i+1));
	}
	cout<<ans;
	return 0;
}
