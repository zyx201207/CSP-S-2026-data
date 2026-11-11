#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int x){
	int k=0;
	for(int i=1;i<=x;i++){
		k+=(a[x]-a[i]);
	}
	if(k<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0,l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
