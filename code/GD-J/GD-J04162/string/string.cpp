#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,a[200010],num=0,p=0,ans=0,mid=0;
string c[200010],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i]>>c[i];
 		ans+=a[i];
 		for(int j=1;j<=a[i];j++)
 		{
 			s+=c[i];
		}
	}
	if(ans%2==1)
	{
		p=ans/2+1;
		mid=ans/2;
		for(int i=mid-1;i>=0;i--)
		{
			if(s[i]!=s[p] && p<ans)
			{
				num++;
			}
		}
		cout<<num;
	}
	else
	{
		p=ans/2;
		mid=ans/2;
		for(int i=mid-1;i>=0;i--)
		{
			if(s[i]!=s[p] && p<ans)
			{
				num++;
			}
		}
		cout<<num;
	}
} 
