#include<bits/stdc++.h>
using namespace std;
const int nx1=1e6;
int c,t,n,x=0,x2=0,y=INT_MAX;
long long d,a[nx1];
bool x1=0;
void dfs(int ly,int lxy,int yy1)
{
	if(x1)
		return;
	if(yy1>y)
		return;
	if(x>2)
	{
		x1=1;
		return;
	}
	if(a[lxy]-ly<=d)
	{
		x++;
		if(yy1<y)
			y=yy1;
		return;
	}
	int xxx;
	for(int i=n-1;i>ly;i--)
		if(a[i]-a[ly]<=d)
		{
			xxx=i;
			break;
		}
	for(int i=xxx;i>ly;i--)
		dfs(i,lxy,yy1+1);
}
int main(){
	preopen("poker.in","r",stdin);
	preopen("poker.out","w",stdout);
	cin>>c>>t;
	for(int lxy2=0;lxy2<t;lxy2++)
	{
		x=0;
		x1=0;
		x2=0;
		y=INT_MAX;
		cin>>n>>d;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
			{
				if(j-i>3)
					continue;
				dfs(i,j,0);
				if(x==2)
					x2++;
			}
		cout<<x2<<'\n';
	}
	return 0;
}

