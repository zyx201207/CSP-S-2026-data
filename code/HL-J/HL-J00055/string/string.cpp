#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],sum[N],l,r,ls,rs,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l=lower_bound(sum+1,sum+n+1,sum[n]/2)-sum;
	if(sum[l]==sum[n]/2)r=l+1,ls=a[l],rs=a[r];
	else r=l,ls=sum[n]/2-sum[l-1],rs=sum[l]-sum[n]/2;
	if(sum[n]%2)rs--;
	if(rs==0)rs=a[++r];
	while(l>0&&r<=n){
		int del=min(ls,rs);
		if(c[l]!=c[r])ans+=del;
		rs-=del,ls-=del;
		if(rs==0)rs=a[++r];
		if(ls==0)ls=a[--l];
	}
	cout<<ans;
	return 0;
}