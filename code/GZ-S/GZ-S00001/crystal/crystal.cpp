//GZ-S00001 ÀîÀ¤Ôª
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
int n,m;
int a[N];
int ans;
bool check(int x){
	int res=0;
	for(int i=1;i<=x;i++) res+=a[x]-a[i];
	if(res<=m) return true;
	bool flag=false;
	for(int i=x+1;i<=n;i++){
		res-=(a[i-1]-a[i-x]);
		res+=(x-1)*(a[i]-a[i-1]);
		if(res<=m){
			flag=true;
			break;
		}
	}
	return flag;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			ans=mid;
			l=mid;
		}
		else r=mid-1; 
	}
	cout<<ans<<endl;
	return 0;
}
