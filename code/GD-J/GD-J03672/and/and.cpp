#include <iostream>
using namespace std;
int n,a[200005],m,maxx=-1,s[200005][35],ans;
bool d[200005],q[35];
int main()
{
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=0;
		while (a[i])
		{
			s[i][x++]=a[i]%2;
			a[i]/=2;
		}
	}
	int p=32;
	while (p+1)
	{
		int df=0;
		for (int i=1;i<=n;i++)
			if (s[i][p]&&!d[i])
				df++;
		if (df>=m)
		{
			for (int i=1;i<=n;i++)
				if (!s[i][p])
					d[i]=1;
			q[p]=1;
		}
		p--;		
	}
	int w=1;
	for (int i=0;i<=30;i++)
		ans+=q[i]*w,w*=2;
	cout<<ans;
	return 0;
} 
