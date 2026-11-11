#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+10; 
int n,m,ma;
int a[N];
int d[N][80],c;
void conv(int x,int p)
{
	c=0;
	while(x)
	{
		d[p][++c]=x&1;
		x>>=1;
	}
	int t[80],cc=c;
	for(int i=1;i<=c;i++)
	{
		t[cc]=d[p][i];
		cc--;
	}
	memcpy(d[p],t,sizeof(t));
	d[p][0]=c;
}
bool chk(int x) //ans>=x
{
	int s=0;
	conv(x,n+1); //x的二进制在d[n+1] 
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		if(d[i][0]<d[n+1][0]) continue;
		for(int j=d[n+1][0];j>=1;j--)
			if(d[n+1][j]==1&&(d[i][j]==0||d[i][0]<j))
			{
				flag=0;
				break;
			}
		if(flag)
		{
			s++;
//			cout<<i<<' ';	
		}
	}
//	cout<<'\n';
//	cout<<x<<' '<<s<<'\n';
//	for(int i=1;i<=d[n+1][0];i++)
//		cout<<d[n+1][i];
//	cout<<'\n';
	return s>=m;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
		conv(a[i],i);
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=d[i][0];j++)
//			cout<<d[i][j];
//		cout<<'\n';
//	}
	int z=1,y=ma,mid;
	while(z<y)
	{
		mid=(z+y+1)>>1;
		if(chk(mid))
			z=mid;
		else
			y=mid-1;
	}
	cout<<z;
}
