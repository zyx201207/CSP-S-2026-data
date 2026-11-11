#include<bits/stdc++.h>
using namespace std;	
int n,m;
int a[200005];
int l[200005];
bool f[200005];
int ans=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			int no = INT_MIN;
			for(int j=1;j<=n;j++)
			{
				f[j]=0;
			}
			for(int j=1;j<=m;j++)
			{
				for(int z=1;z<=n;z++)
				{
					if(f[z]!=1&&i!=z)
					{
						f[z]=1;
						int b =  a[i]&a[z];
						no = max(b,no);
					}	
				}
			}
			ans = max(no,ans);
		}	
	}else{
		
		for(int i=1;i<=m;i++)
		{
			int no = INT_MIN;
			int q=1;
			for(int j=1;j<=n;j++)
			{
				if(f[j]!=1)
				{
					if(no<a[j])
					{
						q = j;
					}
					no = max(no,a[j]);
					
				//	cout<<no<<" ";
				}
			}
			f[q]=1;
			if(i==1)
			{
				ans = no;
			}else{
				int b = ans&no;
				ans = b;
			}
		}
	}
	cout<<ans;
	return 0;
 } 
