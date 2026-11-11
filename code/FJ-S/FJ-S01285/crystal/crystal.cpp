// Thanks for judging my code!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define maxn 500005
using namespace std;
int n;
ll m;
ll a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n){
		scanf("%lld",a+i); 
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		s[i]=s[i-1]-a[i];
	}
	int ans=1;
	rep(i,1,n){
		int l=1,r=i,mid;
		int res=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*1ll*(i-mid+1ll)+(s[i]-s[mid-1])<=m)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	printf("%d",ans);
	return 0;
}
// Oct31==Dec25?
// 1= 1= 1= 1= 1= 1= 1= 1=
// Accepted!
// Good Luck
// 100pts
// What can I say?
// What can I do?
// I love CCF.
