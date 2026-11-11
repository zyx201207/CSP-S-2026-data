#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],s,sum[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n%2)
		s=a[(n-1)/2+1];
	else
		s=(a[n/2]-min(a[n/2],a[n/2+1])+a[n/2+1]-min(a[n/2],a[n/2+1]))/2+min(a[n/2],a[n/2+1]);
	for(int i=1;i<=n;i++)
		sum[i]=abs(s-a[i]);
	sort(sum+1,sum+n+1);
	for(int i=1;i<=n&&m>=sum[i];i++)
		ans++,m-=sum[i];
	cout<<ans;
	return 0;
} 
