#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],num,ans=0;
string s;
bool cf(long long x)
{
	while(x!=1)
	{
		
		if(x%2)
		{
			return 0;
		}
		x=x/2;
	}
	return 1;
}
bool A(long long x)
{
	for(long long i=1;i<=n;i++)
	{
		if(!cf(a[i]+1))return 0;
	}
	sort(a+1,a+n+1);
	return 1;
}
bool B(long long x)
{
	if(!cf(x))return 0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]!=i-1)
		{
			return 0;
		}
	}
	return 1;
}
//string f(long long x)
//{
//	string a,b;
//	while(x!=0)
//	{
//		y++;
//		if(x%2)
//		{
//			a+='1';
//			x/=2;
//		}
//		else
//		{
//			a+='0';
//			x/=2;
//		}
//	}
//	return a; 
//}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
			cin>>a[i];
	}  
	if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;return 0;
	}
	if(m==n)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}  
		cout<<ans;return 0;
	}
	if(m==2)
	{
		for(long long int i=1;i<=n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;return 0;
	}
	if(m==3)
	{
		for(long long int i=1;i<=n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				for(long long int k=j+1;k<=n;k++)
				{
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans; return 0;
	}
	if(m==4)
	{
		for(long long int i=1;i<=n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				for(long long int k=j+1;k<=n;k++)
				{
					for(long long int l=k+1;l<=n;l++)
					{
						ans=max(ans,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<ans; return 0;
	}
	if(B(n))
	{
		ans=n-1;
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(A(n))
	{
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
//	if(m==n-1)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			long long ans2;
//			for(int j=1;j<=n;j++)
//			{
//				ans2=0;
//				if(j!=i)
//				{
//					cout<<ans2<<" ";
//					if((j==1)||(j==2&&i==1))ans2=a[i];
//					else ans2=ans2&a[i];
//					//cout<<i<<" "<<j;
//					cout<<a[i]<<" "<<ans2<<endl; 
//				}
//				ans=max(ans2,ans);
//				cout<<"!"<<ans2<<endl;
//			}
//			
//		}
//		cout<<ans;return 0;
//	}
	
	return 0;
}

