#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tt{
	int x;
	char c;
}a[200005];
int n,l,r,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	l=1,r=n;
	for(;l<r;){
		int t=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c) ans+=t;
		a[l].x-=t,a[r].x-=t;
		if(a[l].x==0) l++;
		else r--;
	}
	cout<<ans; 
	return 0;
}
