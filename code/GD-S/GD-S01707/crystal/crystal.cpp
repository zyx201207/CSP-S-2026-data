#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0,sum=a[1];
	while(r<=n){
		if((r-l+1)*a[r+1]-sum<=m){
			r++;
			sum+=a[r];
		}else{
			sum-=a[l];
			l++;
		}
		if(r-l+1>1)
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0; 
} 
