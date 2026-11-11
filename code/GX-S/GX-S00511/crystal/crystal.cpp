#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m,ans;
int a[N],sum[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=n;i++){
		int l=1,r=i,num=1;
		
		int tmp=i;
		while(tmp+1<=n&&a[tmp+1]==a[tmp])num++,tmp++;
		
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
		
		num+=(i-l);
		
		ans=max(ans,num);
		i=tmp;
	}
	
	cout<<ans;
	return 0;
}
