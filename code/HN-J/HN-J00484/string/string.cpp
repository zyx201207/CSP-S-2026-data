#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int n;
int a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int cnt=0,next=0,last=0;//改变次数，还没改变需要下一次去改变，这次改完还剩下的。
	char nexs,lass;//下一次需要改成啥字母，剩下了啥字母 
	for(int i=1,j=n;i<=(n+1)/2;)
	{
		if(next!=0)
		{
			if(a[j]>=next)//这一次数量够了 
			{
				last=a[j]-next;//还剩多少 
				if(c[j]!=nexs) cnt+=next;//如果字母不一样就要改数字 
				if(next==0) j--;//没了接着用下一个配对 
				else i++;j--;//接着配对 
				next=0;
			}
			else//还不够 
			{
				if(c[j]!=nexs) cnt+=next;//如果字母不一样就要改数字 
				next-=a[j];
				j--;
			} 
		}
		else if(last!=0)
		{
			if(a[i]<=last+a[j])
			{
				last=last-(a[i]-a[j]);
				if(lass!=c[i]) cnt+=a[i];
				if(last==0)
				{
					j--;
					i++;
				}
				else
				{
					i++;
				}
			}
			else
			{
				next=a[i]-(last+a[j]);
				nexs=c[i];
				j++;
			}
		}
		else
		{
			if(a[i]<=a[j])
			{
				last=last-(a[i]-a[j]);
				if(c[i]!=c[j]) cnt+=a[j];
				if(last==0) 
				{
					j--;
					i++;
				}
				else
				{
					i++;
				}
				lass=c[j];
			}
			else
			{
				next=a[i]-(last+a[j]);
				nexs=c[i];
				if(c[j]!=c[i])cnt+=a[j];
				j++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
