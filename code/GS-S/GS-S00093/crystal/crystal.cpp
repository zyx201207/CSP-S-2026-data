#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const long long N=500005;
long long a[N],d[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
		b[i]=b[i-1]+d[i]*i;
		if(b[i]>m){
			ans=i;
		break;
		}
	}
	cout<<ans;
	return 0;
} 
