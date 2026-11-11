#include<bits/stdc++.h>
using namespace std;
long long a[2000001],k[5001][5001],z[5001][5001],s;
long long t,t1,n,m;
int dfs(int q,int h,int x,int b)
{
	int ma=0;
	if(b>z[q][h])
	return 0;
	if(x==h){
	return 1;
	}
	for(int i=x+1;i<=h;i++)
	if(a[i]-a[x]<=m){
	ma+=dfs(q,h,i,b+1);
	}
	else
	return ma;
	return ma;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t1;
	for(int it=1;it<=t1;it++)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
		cin>>a[i];
		}
		if(t==11||t==12){
		int k=m/(a[2]-a[1]);
		k=k*2-1;
		if(n>k&&k>1)
		cout<<n-k<<endl;
		else
		cout<<0<<endl;
		}
		else if(t<=10)
		{
			s=0;
			for(int i=3;i<n;i++)
			{
				for(int l=1;l<=n-i;l++)
				{
					int b=l,c=l+i,d=m,e=1;
					while(b<c)
					{
						if(a[b+1]-a[b]>d)
						{
							e++;
							d=m-a[b+1]+a[b];
						}
						else
						d-=a[b+1]-a[b];
						b++;
					}
					z[l][l+i]=e;
					if(dfs(l,l+i,l,0)==2)
					s++;
				}
			}
			cout<<s<<endl;
		}
		else
		cout<<0<<endl;
	}
	return 0;
}
//bad bird
