#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxm=3e1+5;
long long n,m,a[maxn],mod[maxn];
long long t[maxn][maxm],z[maxn];
long long tong[maxm],b[maxn];
long long maxt=-1,tmp;
bool cmp(int x,int y)
{
	int a[31],b[31];
	int j=maxt,xx=x,yy=y;
	while(xx)
	{
		a[j--]=xx%2;
		xx/=2; 
	}
	while(yy)
	{
		b[j--]=yy%2;
		yy/=2; 
	}
	for(int i=tmp;i>=1;i--)
	{
		if(a[i]&&!b[i])
		{
			return false;
		}
		if(!a[i]&&b[i])
		{
			return true;
		}
	}
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=31;i++)
	{
		mod[i]=pow(2,i);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=31;j++)
		{
			if(a[i]/mod[j]!=0)
			{
				z[i]=j;
			}
		}
		z[i]++;
		maxt=max(maxt,z[i]);
		//cout<<z[i]<<" ";
	} 
	//cout<<endl;
	for(int i=1;i<=n;i++)
	{
		int j=maxt,x=a[i];
		while(x)
		{
			t[i][j--]=x%2;
			x/=2; 
		}
		for(int j=1;j<=maxt;j++)
		{
			//cout<<t[i][j];
			if(t[i][j])
			{
				tong[j]++;
			}
		}
		//cout<<endl;
	} 
	for(int i=31;i>=1;i--)
	{
		if(tong[i]>=m)
		{
			tmp=i;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i][tmp])
		{
			b[++cnt]=a[i];
		}
	}
	sort(b+1,b+cnt+1);
	for(int i=cnt;i>=cnt-m+1;i--)
	{
		//cout<<b[i]<<" ";
	}
	int ans=b[cnt]; 
	for(int i=cnt;i>=cnt-m+1;i--)
	{
		ans&=b[i];
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
10 10
1 2 3 4 5 6 7 8 9 10
*/
