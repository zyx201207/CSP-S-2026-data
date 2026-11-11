#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
int n,m;
int ans;
int a[N+5];
int sum[N+5];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i){
		int L=0,R=i;
		while(L+1<R){
			int mid=L+R>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
				R=mid;
			else L=mid;
		}
		ans=max(ans,i-R+1);
	}
	cout<<ans;
	return 0;
}

