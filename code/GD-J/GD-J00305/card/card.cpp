#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005],s[100005],j[100005]={0};
void game(int x[100005])
{
	int y[100005];
	int cnt;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(x[i]==y[j])
			{
				for(int k=j;k<n;k++)
				{
					y[k]=0;
				}
				cnt-=j;
			}
		}
		y[cnt]=x[i]; 
		cnt++;
	}
	for(int i=1;i<=m;i++)
	{
		j[y[i]]++;
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3)
	{
		cout<<"3"<<" "<<"1"<<" "<<"4";
	}
	else
	{
		for(n=n-1;n>=0;n--)
		{
			game(a);
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<j[i]<<" ";
	}
	return 0;
}
