#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,t[N][30],x,i,maxa,js,ans,j,m,a;
void figure()
{
	x=0;
	while(a!=0)
	{
		t[i][x]=a%2;
		a/=2;
		x++;
	}
}
int pow(int y)
{
	int s=1;
	for(int k=1;k<=y;k++)
		s*=2;
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		figure();
		if(m==1)
			maxa=max(maxa,a);
	}
	if(m==1)
	{
		cout<<maxa;
		return 0;
	}
	if(m==n)
	{
		for(i=0;i<30;i++)
		{
			js=0;
			for(j=1;j<=n;j++)
				if(t[j][i]==1)
					js++;
			if(js%2==0&&js!=0)
				ans+=pow(i);
		}
		cout<<ans;
	}
		return 0;
	return 0;
}
