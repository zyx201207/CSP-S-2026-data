#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000005];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long r=1,sum=0;
	for(int l=1;l<=n;l++){//左指针 
		while(r<=n){
			//扩展之前先检查是否可以扩展
			if((r-l+1)*(a[r+1]-a[r])+sum>m) break;
			//无法扩展，break
			r++;
			sum=(r-l)*(a[r]-a[r-1])+sum; 
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
