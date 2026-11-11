#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int bin[N][35];
int c[35];
int a[N];
int mult2[35];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	mult2[0]=1;
	for (int i=1;i<=35;i++)
	{
		mult2[i]=mult2[i-1]*2;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+1+n,cmp);
	
	for (int i=1;i<=n;i++)
	{
		int l=0,x=a[i];
		while (x!=0)
		{
			if (x&1)
			{
				bin[i][l++]=1;
			}
			else bin[i][l++]=0;
			x>>=1;		
		}			
	}
//	for (int i=1;i<=n;i++)
//	{
//		cout<<":"<<i<<" ";
//		for (int j=0;j<5;j++)
//		{
//			cout<<bin[i][j]<<" ";
//		}
//		cout<<endl;	
//	}
	long long ans=0;
	long long len=n;
	for (int i=30;i>=0;i--) 
	{
		int cnt=0;
		for (int j=1;j<=len;j++)
		{
			if (bin[j][i] == 1)cnt++;
		}
		if (cnt >= m)
		{
			ans+=mult2[i];
			len=cnt;
		}
	}
	cout<<ans;	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
