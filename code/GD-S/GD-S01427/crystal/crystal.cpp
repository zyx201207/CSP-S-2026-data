#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qzh[500005];
long long ans=1;
bool pd(long long l,long long r)
{
	if(m>=a[r]*(r-l+1)-(qzh[r]-qzh[l-1]))
	return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	qzh[i]=qzh[i-1]+a[i];
	long long r=1;
	for(long long i=1;i<=n;i++)
	{
		while(pd(i,r)&&r<=n)r++;
		ans=max(ans,r-i);
	}
	cout<<ans;
	return 0;
}
