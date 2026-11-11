#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=2,maxx=0;
	int a[500005],b[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	b[500005]=a[500005];
		int s;
		s=a[1]-a[0];
		a[0]+=(m+s)/2;
		a[1]+=(m-s)/2;
		for(int j=2;j<n;j++)
		{
			if(a[j]==a[0])
				cnt++;
			
		}
		if(cnt>=maxx)
		{
			maxx=cnt;
		}
		a[500005]=b[500005];
	
	
	cout<<maxx;
	return 0;
}