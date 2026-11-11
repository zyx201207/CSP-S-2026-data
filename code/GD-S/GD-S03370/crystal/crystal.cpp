#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
bool chk(int x){
	for(int i=x;i<=n;i++)
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,res=1;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))res=mid,l=mid+1;
		else r=mid-1;
	}	
	cout<<res;
	return 0;
}
