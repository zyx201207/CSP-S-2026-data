#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	vector<long long>a(n+1),sum(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		long long l=1,r=i,anss=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid-1,anss=mid;
			else l=mid+1;
		}
		ans=max(ans,i-anss+1);
	}
	cout<<ans;
	return 0;
} 
