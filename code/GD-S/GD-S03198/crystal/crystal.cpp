#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],pre[500005],sum[500005],d;
bool flag=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],pre[i]=pre[i-1]+a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		int ans=0;
		for(int i=1;i<=n;i++){
			int cur=0;
			for(int j=i-1;j>=1;j--){
				if(cur+a[i]-a[j]<=m)cur+=a[i]-a[j],ans=max(ans,i-j+1);
				else break;
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		int l=0,r=i+1,mid=0;
		while(l+1<r){
			mid=(l+r)/2;
			if(mid*(mid+1)>(m*2+d-1)/d)r=mid;
			else l=mid;
		}
		ans=max(ans,l+1);
	}
	cout<<ans;
	return 0;
}
