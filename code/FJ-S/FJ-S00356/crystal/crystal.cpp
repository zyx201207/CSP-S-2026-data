#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,a[N],cnt;
int check(int x){
	int l=1,ans=0,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(a[mid]<=x)l=mid;
		else r=mid;
	}
	for(int i=l;i>=1;i--){
		cnt-=x-a[i];
		if(cnt<0)return ans;
		ans++; 
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int l=1e17,r=-1;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int ans=-1;
	l=a[1]-1;
	r=a[n]+1;
	while(l+1<r){
		int mid=(l+r)/2;
		cnt=m;
		int t=check(mid);
		if(cnt>0)l=mid;
		else r=mid;
		ans=max(ans,t);
	}
	cout<<ans;
} 
