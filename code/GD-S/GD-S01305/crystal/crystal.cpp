# include<bits/stdc++.h>
# define int long long
using namespace std;
int a[1000001],qzh[1000001],n,m,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)qzh[i]=qzh[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(a[i]*mid-(qzh[i]-qzh[i-mid])>m)r=mid-1;
			else l=mid;
		}
		ans=max(ans,l);
	}
	cout<<ans;
}
