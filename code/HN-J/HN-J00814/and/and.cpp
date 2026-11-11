#include<bits/stdc++.h>
using namespace std;
long long a[200050][500],b[200050][500],x[200500],ans,v,bb=1,k,al;
int n,m;

int s(int q,int w,int zh)
{
	for(int i=0;i<v;i++)
	{	
		if(b[q][i]==1&&a[w][i]==1)
		{
			b[bb][i]=1;
		}
			else
		{
			b[bb][i]=0;
		}
	}
	bb++;
	return bb-1;
}

int p(int r,int rr,int l,int t)
{
	if(t<=1)
	{
		return 0;
	}
	for(int i=rr;i<l;i++)
	{
		return p(s(r,i,t),rr+1,l,t-1);
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<n;i++)
	{
		k=0;
		while(x[i]!=0)
		{
			if(x[i]%2==0)
			{
				a[i][k]=0;
				k++;
			}
			else
			{
				a[i][k]=1;
				k++;
			}
			v=max(v,k)+1;
			x[i]/=2;
		}
	}
	for(int i=0;i<v;i++)
	{
		b[0][i]=a[0][i];
	}
	p(0,0,n,m);
	for(int i=0;i<bb;i++)
	{
		al=0;
		for(int j=0;j<=v;j++)
		{
			al+=b[i][j]*pow(2,j);
		}
		if(al>ans)
		{
			ans=al;
		}
	}
	cout<<ans;
	return 0;
 } 
