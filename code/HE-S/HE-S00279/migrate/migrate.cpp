#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
int a[2000010];
int t[2000010];
int lj = 0,sum = 0;
void f(int q,int z,int bs,int wz,int zd)
{
	if(wz>z)
	{
		return;
	}
	if(wz==z)
	{
	//	cout<<"gay"<<' ';
		if(bs<zd)
		{
			zd = bs;
			lj = 0;
			lj++;
		}
		else if(bs==zd)
		{
			lj++;
		}
	//	zd--;
	//	cout<<zd<<' ';
	//	lj++;
		return;
	}
	for(int i = 1;i<=d;i++)
	{
		if(t[wz+i]==1)
		{
			f(q,z,bs+1,wz+i,zd);
		}
	}
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		for(int i = 1;i<=n;i++)
		{
			t[a[i]] = 0;
		}
	//	sizeof(0,t);
		n = d = 0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			t[i] = 0;
			cin>>a[i];
			t[a[i]]=1;
		}
		sum = 0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				lj = 0;
				f(a[i],a[j],1,a[i],1e8);
			//	cout<<lj<<' ';
				if(lj==2)
				{
					sum++;
				}
			}
		}
	//	cout<<endl;
		cout<<sum<<endl;
	}
	return 0;
}
