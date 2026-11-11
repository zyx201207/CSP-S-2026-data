#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e6+10;

int n,m;
int a[N],b[N];
int ans;
inline bool check(int x){
	int pre=0,res=0;
	for(int i=1;i<x;i++){
		res+=b[i]*i;
		pre+=b[i];
	}if(res<=m) return true;
	for(int i=x;i<=n;i++){
		res-=pre;
		pre-=b[i-x+1];
		pre+=b[i];
		res+=b[i]*(x-1);
		if(res<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1; 
	}
	cout<<ans;
	return 0;
} 
