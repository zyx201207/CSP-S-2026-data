#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,idx=0,ans=0;
int a[200005];
char c[200005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;c[0]='#';
	for(int i=1;i<=n;i++)
	{
		idx++;
		cin>>a[idx]>>c[idx];
		if(c[idx]==c[idx-1]){a[idx-1]+=a[idx];idx--;}
	}
	if(idx==1){cout<<0;return 0;}
	int l=1,r=idx;
	while(l<=r)
	{
		if(c[l]==c[r] && a[l]==a[r]){l++,r--;continue;}
		if(c[l]==c[r] && a[l]>a[r]){a[l]-=a[r];r--;}
		if(c[l]==c[r] && a[l]<a[r]){a[r]-=a[l];l++;}
		if(c[l]!=c[r] && a[l]==a[r])
		{
			ans+=a[l];
			l++,r--;
		}
		if(c[l]!=c[r] && a[l]>a[r])
		{
			ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		if(c[l]!=c[r] && a[l]<a[r])
		{
			ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}cout<<ans;
	return 0;
}
