#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int por[31];
int wei[N][31];
int k;
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
void worka()
{
	cout<<a[m];
	return ;
}
void workb()
{
	for(int i=1;i<=n;i++)
	{
		int p=1;
		for(int j=0;j<=k;j++)
		{
			if(!wei[i][j])p*=2;
		}
		if(p+1>=m)
		{
			cout<<i;
			return ;
		}
	}	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int oka=0,okb=0;
	cin>>n>>m;
	for(int i=0;i<=30;i++)por[i]=1<<i;
	for(int i=0;i<=30;i++)
	{
		if(n==por[i])
		{
			okb=1,k=i;
			break;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		oka=0;
		for(int j=0;j<=30;j++)
		{
			if(a[i]==(por[j])-1)
			{
				oka=1;
			}
			wei[i][j]=(a[i]&(1<<j)!=0)?1:0;
		}
		if(a[i]!=i-1)
		{
			okb=0;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(oka)
	{
		worka();
		return 0;
	}
	if(okb)
	{
		workb();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			if((a[i]&a[j])==a[i])c++;
			if(c+n-j<m-1)break;
		}
		if(c>=m-1)
		{
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}
/*
10 3
0 1 2 3 4 5 6 7  8 9

*/
