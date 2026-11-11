#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int x=1,y=0,cnt=1;
	ans=1;
	for(int i=2;i<=n;i++){
		y+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(y>m){
			y-=a[i]-a[x];
			cnt--,x++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
