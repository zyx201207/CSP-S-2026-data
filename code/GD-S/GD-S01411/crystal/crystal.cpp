#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	
	
	int l=n,r=n,ans=1,cntt=m,last=0,jizhu=0;
	while(l>0&&r>=1){
		if (jizhu==1){
			cntt+=(last-1)*(a[r+1]-a[r]);
			last-=1;
		}
		
		while(l>0&&cntt-(a[r]-a[l])>=0){
			cntt-=(a[r]-a[l]);
			last++;
			l--;
			
		}
		ans=max(ans,last);
		jizhu=1;
		r--;
	}
	cout<<ans;
	return 0;
}
