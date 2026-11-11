#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5+5;

int n,m,a[N],q[N],sum[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

	int l=1,r=0,len,SUM;
	for (int i=1;i<=n;i++)
	{
		r++;
		SUM=sum[r]-sum[l-1],len=r-l+1;
		while (l<=r && (SUM+m)/len<a[r]){
			l++;
			SUM=sum[r]-sum[l-1],len=r-l+1;
		}
		q[r]=r-l+1;
	}
	
	for (int i=1;i<=n;i++)
		ans=max(q[i],ans);
	cout<<ans;

	return 0;
}
