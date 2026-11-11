#include<bits/stdc++.h>
#define int long long
#define cin(x) x=read()
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],num[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		num[i]=b[i]+num[i-1];
	}
	int r=0,ans=1,cnt=0;
	for(int l=1;l<=n;l++){
		while(r+1<=n&&cnt+(r-l+1)*b[r+1]<=m){
			cnt+=(r-l+1)*b[r+1];
			r++;
		}
		ans=max(ans,r-l+1);
		cnt-=num[r]-num[l-1];
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
