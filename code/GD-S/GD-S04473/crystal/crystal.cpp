#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500009];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1,r=1,ans=0,sum=a[1];
	while(r<=n){
		if(a[r]*(r-l+1)-sum<=m){
			ans=max(ans,r-l+1);
			r++;
			sum+=a[r];
		}else{
			sum-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
