#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6;
int n,ans=1,last;
LL m,a[N+10];
unsigned long long sum[N+10];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])last=i;
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
		if(m>=sum[i]){
			ans=i;
			continue;
		}
		int l=1,r=last-1;
		while(l<=r){
			int mid=l+r>>1;
			if(sum[i]-sum[mid]-1LL*mid*(a[i]-a[mid])<=m){
				ans=max(ans,i-mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
