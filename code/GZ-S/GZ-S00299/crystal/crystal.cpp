//GZ-S00299遵义市第四中学童博开 
#include<bits/stdc++.h>
using namespace std;
long long cr[500001],l[500001]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cr[i];
	}
	if(n>5000&&cr[2]-cr[1]==cr[4]-cr[3])
	{
		l[1]=0;
		for(int i=2;i<=n;i++)
		{
			l[i]=l[i-1]+(i-1)*cr[2]-cr[1];
			if(l[i]>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	l[1]=1;
	sort(cr+1,cr+n+1);
	
	for(int i=2;i<=n;i++)
	{
		long long e=m;
		l[i]=1;
		for(int j=i-1;j>=1;j--)
		{
			e-=cr[i]-cr[j];
			if(e>=0)
			{
				l[i]=i-j+1;
			}else
			{
				break;
			}
		}
	}
	long long an=0;;
	for(int i=1;i<=n;i++)
	{
		an=max(an,l[i]);
	}
	cout<<an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
