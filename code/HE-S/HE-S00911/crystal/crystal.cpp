#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[510000],b[510000],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}	
	int l=0,r=1,k=0;
	while(l<=n&&r<=n){
		if((r-l+1)*a[r]-(b[r]-b[l-1])<=m){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
