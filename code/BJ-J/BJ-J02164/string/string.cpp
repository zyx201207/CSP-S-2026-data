#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n,a[N],x[N],cnt,len,ans;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=a[i];j>=1;j--) x[++cnt]=c[i];
	}
	int l=1,r=len;
	while(l<=r)
	{
		if(x[l]!=x[r]) ans++;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
