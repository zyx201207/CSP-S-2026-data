#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans=0,t[N],c[N];
bool check(int x,int l)
{
	ll cost=c[x]-c[l-1]-(a[x]-a[l-1])*(l-1);
	if(cost>m) return 0;
	else return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) t[i]=a[i+1]-a[i]; 
	for(int i=n-1;i>=1;i--) t[i]=t[i]+t[i+1];
	for(int i=2;i<=n;i++) c[i]=(t[i-1]-t[i])*(i-1)+c[i-1];
	for(int i=1;i<=n;i++){
		int l=i,r=n,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)) l=mid+1,res=mid-i+1;
			else r=mid-1;
		}
		ans=max(ans,res*1LL);
	}
	cout<<ans<<'\n';
	return 0;
}
