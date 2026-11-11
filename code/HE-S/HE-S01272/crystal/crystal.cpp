#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
bool fun(int mid){
	int sum=0;
	for(int i=1;i<mid;i++){
		sum+=a[mid]-a[i];
	}
	for(int i=mid+1;i<=n;i++){
		if(sum<=m)return 1;
		sum-=a[i-1]-a[i-mid];
		sum+=(a[i]-a[i-1])*(mid-1);
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(fun(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
