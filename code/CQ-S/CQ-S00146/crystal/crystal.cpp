#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l,r,ans,cnt=1,k;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;k=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*cnt<=k)k-=(a[i]-a[i-1])*cnt,cnt++;
		else break;
	}
	ans=cnt;
	for(int i=2;i<=n;i++){
		k+=a[cnt]-a[i-1];
		int j=cnt;
		while(k>=0&&j<=n)j++,k-=(a[j]-a[j-1])*(j-i);
		k+=(a[j]-a[j-1])*(j-i);
		cnt=j-1;
		ans=max(ans,cnt-i+1);
		if(cnt==n)break;
	}
	cout<<ans;
	return 0;
} 


