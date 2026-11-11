#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],sum[maxn],ans=1;
bool check(int d,int now){
	int t=sum[now]-sum[d-1];
	if(a[now]*(now-d+1)-t<=m)return 0;
	else return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[n+1]=a[n]+1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i))l=mid+1;
			else {
				ans=max(ans,i-mid+1);
				r=mid;
			}
		}
	}
	cout<<ans;
	return 0;
}
