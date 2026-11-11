#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],sum[500005];
int ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r=0,l=0;
	int num=0;
	while(r<=n){
		sum[r]=sum[r-1]+a[r];
		if(a[r]*(num)-sum[r]+sum[l-1]>m)l++,num--;
		else ans=max(num,ans);
		r++;
		num++;
	}
	cout<<ans;
	return 0;
}
