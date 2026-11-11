#include<bits/stdc++.h>
using namespace std;
int c,d,n,q,x[100005],y[100005];
long long m,ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+5],a[n+5][m+5],t[n+5][m+5];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];	
	} 
	for(int i=1;i<=n;i++)
	{
		int e;
		cin>>e;
		for(int j=1;j<=e;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}	
	} 
	
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c==20||c==21)
	{
		
		if(n==1){
			for(int i=1;i<=q;i++)
			{
				ans=w[x[i]]+w[y[i]];
				for(int j=x[i];j<=y[i];j++)
				{
					ans+=t[1][j];	
				}	
				cout<<ans;	
			}
			 
		}else{
			int l,k;
			while(a[1][k]!=0)
			{
				while(a[2][l]!=0)
				{
					if(a[1][k]==a[2][l])
					{
						ans+=a[1][k]+a[2][l];
					} 
					l++;	
				}
				k++;
			}
			for(int i=1;i<=q;i++)
			{
				ans=w[x[i]]+w[y[i]];
				for(int j=x[i];j<=a[1][k];j++)
				{
					ans+=t[1][j];	
				}
				for(int j=a[1][k]+1;j<=y[i];j++)
				{
					ans+=t[2][j];	
				}	
				cout<<ans;	
			}	
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
