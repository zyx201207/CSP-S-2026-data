#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;long long a[N],m,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=1,R=i-1,res=-1;
		while(L<=R){
			int mid=L+R>>1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1])<=m)res=mid,R=mid-1;
			else L=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}