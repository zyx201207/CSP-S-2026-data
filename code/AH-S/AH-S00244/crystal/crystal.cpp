#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
LL m,a[N],s[N];
int n;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int res=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(1ll*a[mid]*(mid-i+1)-(s[mid]-s[i-1])<=m) l=mid;
			else r=mid-1;
		}
		res=max(res,r-i+1);
	}
	cout<<res<<"\n";
	return 0;
}