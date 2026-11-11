#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,s=0,l=1,r;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(l<r)
	{
		if(b[l]==b[r])
		{
			if(a[l]>a[r])
				a[l]-=a[r],r--;
			else if(a[l]==a[r])
				l++,r--;
			else
				a[r]-=a[l],l++;
		}
		else
		{
			if(a[l]>a[r])
				a[l]-=a[r],s+=a[r],r--;
			else if(a[l]==a[r])
				s+=a[l],l++,r--;
			else
				a[r]-=a[l],s+=a[l],l++;
		}
	}
	cout<<s;
	return 0;
}

