#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans=1;
bool check(int x,int i){
	int sum1=a[i]*(i-x+1);
	if(sum1-(b[i]-b[x-1])<=m)return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,sum=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(mid,i))sum=max(sum,i-mid+1),r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
