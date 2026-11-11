#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	while(l<=r){
		while((a[r]*(r+l-1)-(sum[r]-sum[l-1])<=m)&&r<=n)
		{
			ans=max(ans,(long long)r-l+1);
			r++;
		}
		l++;
	}
	cout<<ans<<endl;
	return 0;
} 
