#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],s[MAXN];
inline int get(int i){
	int l=1,r=i,res=i;
	while(l<=r){
		int mid=l+r>>1;
		if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int lst=get(i);
		ans=max(ans,i-lst+1);
	}
	cout<<ans<<"\n";
}