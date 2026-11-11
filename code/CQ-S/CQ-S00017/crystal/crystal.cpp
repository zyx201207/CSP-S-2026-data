#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,xm,lf=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=(a[i]-a[i-1])*(i-lf);
		if(xm+t<=m){
			xm=xm+t;
			ans=max(ans,i-lf+1);
		}else{
			while(xm+t>m){
				xm-=(a[i]-a[lf]);
				lf++;
			}
			xm=xm+t;
			ans=max(ans,i-lf+1);
		}
	}
	cout<<ans;
	return 0;
}
