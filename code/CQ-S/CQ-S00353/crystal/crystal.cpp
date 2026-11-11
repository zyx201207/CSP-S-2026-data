#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,sum[500010],a[500010],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int now=0,r=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mid(l+r>>1);
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
