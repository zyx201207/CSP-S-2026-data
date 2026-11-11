#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,maxx,li,l[200005],ans,q,k;
bool pd[200005],s[200005][35];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		while(a[i]>0)
 		{
 			s[i][++sum]=a[i]%2;
 			a[i]=a[i]/2;
		}
		maxx=max(maxx,sum);
	}
	int sum=0,li=0;
	for(int j=maxx;j>=1;j--)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][j]==1)sum++;
		}
		if(sum>=m)
		{
			for(int i=1;i<=n;i++)
			{
				if(s[i][j]==1)l[++li]=i;
				if(li==m)break;
			}
			break;
		}
	}
	sum=0;
	for(int i=1;i<=maxx;i++)
	{
		bool p=1;
		for(int j=1;j<=li;j++)
		{
			if(s[j][i]==0)
			{
				p=0;
				break;
			}
		}
		sum+=p*(1<<k);
		k++;
	}
	cout<<sum;
	return 0;
}


