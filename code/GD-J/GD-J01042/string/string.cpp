#include<bits/stdc++.h>
using namespace std;
string st;
char ch[200005];
long long n,x[200005],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>ch[i];
	long long l=1,r=n;
	while(1)
	{
		if(x[l]<x[r])
		{
			if(ch[l]!=ch[r]) ans+=x[l];
			x[r]-=x[l],x[l]=0,l++;
		}
		else
		{
			if(x[l]==x[r])
			{
				if(ch[l]!=ch[r]) ans+=x[l];
				x[r]=0,x[l]=0,l++,r--;
			}
			else if(x[l]>x[r])
			{
				if(ch[l]!=ch[r]) ans+=x[r];
				x[l]-=x[r],x[r]=0,r--;
			}
		}
		if(l>r) break;
	}
	cout<<ans;
	return 0;
}
