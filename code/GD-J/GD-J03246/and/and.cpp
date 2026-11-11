#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,j=0,z=0,k=0,c=0;
	freopen("and.in");
	freclose("and.out");
	int s[a];
	int d[a][10000000];
	for(int i=0;i<a;i++)
	{
		j=0;
		cin>>s[i];
		while(s[i]!=0)
		{
			d[i][j]=s[i]%2;
			s[i]=s[i]/2;
			j++;
		}
		z=max(z,j);
	}
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<z;j++)
		{
			if(d[i][j]!=1)
			{
				d[i][j]=0;
			}
		}
	}
	long long f=z;
	for(int i=0;i<a;i++)
	{
		f=z;
		for(int j=0;j<z;j++)
		{
			swap(d[i][j],d[i][f]);
			f--;
		}
	}
	for(int i=1;i<=z-1;i++)
	{
		k=k+i;
	}
	int m[k][z];
	for(int i=0;i<a-1;i++)
	{
		for(int h=i+1;h<a;i++)
		{
		    for(int j=0;j<z;j++)
		    {
			    if(d[i][j]==d[h][j]&&d[i][j]==1)
			    {
				    m[i][j]=1;
			    }
			    else
			    {
				    m[i][j]=0;
			    }
		    }
	    }
	}
	long long r[k];
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<k;j++)
		{
			r[i]=r[i]*10+m[i][j];
		}
		c=max(c,r[i]);
		cout<<c<<' ';
	}
	int op=c;
	int ans=0;
	int mj[z];
	int i=z;
	while(c!=0)
	{
		mj[i]=c%10;
		c=c/10;
		i--;
	}
	for(int j=0;j<z;j++)
	{
		ans=ans*2+mj[j];
	}
	cout<<ans;
	return 0;
}
