#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N];
bool ch(int x){
	int res=m,j=n-x;
	for(int i=n-1;i>n-x;i--) res-=a[n]-a[i];
	if(res>=0) return 1;
	for(int i=n-1;i>=x;i--,j--){
		res+=b[i+1]*(x-1);
		if(j>0) res-=a[i]-a[j];
		if(res>=0) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ch(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<res;
} 
