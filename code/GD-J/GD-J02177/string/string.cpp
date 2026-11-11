#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],sum,ans;
char s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	long long z=1,y=sum,l=1,r=n;
	while(z<y)
	{
		long long m=min(a[l],a[r]);
		if(s[l]!=s[r]) 	
			ans+=m;
		y-=m,z+=m;
		if(a[l]>m) a[l]-=m,r--;
		else if(a[r]>m) a[r]-=m,l++;
		else r--,l++;
	}
	cout<<ans;
	return 0;
}
