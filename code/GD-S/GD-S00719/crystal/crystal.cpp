#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=0,sum=0;
	while(l<=n&&r<=n){
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
			sum+=(r-l)*(a[r]-a[r-1]);
		}else{
			sum-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
