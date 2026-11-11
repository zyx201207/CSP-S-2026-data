#include<bits/stdc++.h>
using namespace std;
#define int long long
const int L=5e5+5;
int n,a[L],m,ans,b[L];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=n,d=0,all=0,num=1;
	for(int i=n;i>0;i--){
		while(l>1&&all<=m){
			d+=a[l]-a[l-1];
			all+=d;
			l--;
			num++;
		}
		if(all>m){
			num--;
			l++;
			all-=d;
			d-=a[l]-a[l-1];
		}
		ans=max(ans,num);
		num--;
		all-=(a[i]-a[i-1])*num;
		d-=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
