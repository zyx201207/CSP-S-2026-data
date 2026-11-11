#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,sum,l,r;
int chs[N];
char ch[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in" ,"r",stdin );
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>chs[i]>>ch[i];
	}
	l=1;r=n;
	while(l<=r)
	{
		if(chs[l]>chs[r])
		{
			if(ch[l]!=ch[r]) sum+=chs[r];
			chs[l]-=chs[r];
			chs[r]=0;
			r--;
		}
		else if(chs[l]<chs[r])
		{
			if(ch[l]!=ch[r]) sum+=chs[l];
			chs[r]-=chs[l];
			chs[l]=0;
			l++;
		}
		else 
		{
			if(ch[l]!=ch[r]) sum+=chs[l];
			chs[l]=0;
			chs[r]=0;
			l++;r--;
		}
	}
	cout<<sum;
	return 0;
}
