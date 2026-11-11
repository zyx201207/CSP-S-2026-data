#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m,ans=0;
void solve(){
	for(int i=1;i<=n;i++){
		int sum=0,j=i-1;
		for(;j>0;j--){
			if(sum+(a[i]-a[j])<=m)sum+=a[i]-a[j];
			else break;
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
}
void solve2(){
	int l=n,r=n,sum=0,ans=0;
	while(l>=1){
		ans=max(ans,r-l+1);
		int num=sum+a[r]-a[l-1];
		if(num>m){
			r--;
			if(r<l){
				l=r;
				sum=0;
				continue;
			}
			sum-=(a[r+1]-a[r])*(r-l+1);
		}else{
			l--;
			sum+=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	solve2();
	return 0;
}
