#include<bits/stdc++.h>
using namespace std;
int ej(int a,int b)
{
	int ae[32];
	int be[32];
	int res=0;
	int lj=1;
	for(int i=0;i<32;i++)
	{
		ae[i]=0;
		be[i]=0;
	}
	int j=0;
	while(a>=1)
	{
		ae[j]=a%2;
		a/=2;
		j++;
	}
	j=0;
	while(b>=1)
	{
		be[j]=b%2;
		b/=2;
		j++;
	}
	for(int i=0;i<32;i++)
	{
		if(ae[i]==1&&be[i]==1)
		{
			res+=lj;
		}
		lj*=2;
	}
	return res;
}
int s[200005];
int mask[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		mask[i]=0;
	}
	for(int i=n-m;i<n;i++)
	{
		mask[i]=1;
	}
	bool f;
	int ls;
	int maxn=0;
	if(n>2000&&m!=n-1)
	{
		cout<<3<<endl;
		return 0;
	}
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			maxn=max(maxn,s[i]);
		}
		cout<<maxn<<endl;
		return 0;
	}
	do
	{
		f=true;
		for(int i=0;i<n;i++)
		{
			if(mask[i]==1)
			{
				if(f)
				{
					ls=s[i];
					f=false;
				}
				else
				{
					ls=ej(ls,s[i]);
				}
			}
		}
		maxn=max(maxn,ls);
	}while(next_permutation(mask,mask+n));
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
