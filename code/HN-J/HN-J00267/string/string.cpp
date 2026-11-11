#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[200005],num=0,ans=0,n;
char a[200005],bb[100000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>b[i]>>a[i];
		num+=b[i];
		
	}
	
	int num2=0,iii=0;
	for(int i=1;i<=n;i++)
	{
		num2+=b[i];
		if(num2>=num/2&&iii==0)
		{
			iii=i;
			break;
		}
	}
	if(num<100000000)
	{
		
		int num5=0;
		for(int i=1;i<=n;i++)
		{
			for(int j = 1;j<=b[i];j++)
			{
				num5++;
				bb[num5]=a[i];
			}
		}
		
		for(int i=1;i<=num5/2;i++)
		{
			if(bb[i]!=bb[num5-i+1])
			{
				ans++;
			}
		}
		cout<<ans<<'\n';
		
		 
		
	}
	else
	{
		int num3=n,num5=0;
		for(int i=1;i<iii;i++)
		{
			int num4=b[i];
			while(num4)
			{
				if(a[i]==a[num3])
				{
					if(num4<b[num3]-num5)
					{
						num5=num4;
						num4=0;
					}
					else
					{
						
						num4-=b[num3]-num5;
						num5=0;
						num3--;
					}
				}
				else
				{
					if(num4<b[num3]-num5)
					{
						
						num5=num4;
						ans+=num4;
						num4=0;
					}
					else
					{
						
						ans+=b[num3]-num5;
						num4-=b[num3]-num5;
						num5=0;
						num3--;
					}
				}
			}
		}
		
		if(num3!=iii)
		{
			int num4=b[iii];
			while(num4&&num3!=iii)
			{
				if(a[iii]==a[num3])
				{
					if(num4<b[num3]-num5)
					{
						num5=num4;
						num4=0;
					}
					else
					{
						
						num4-=b[num3]-num5;
						num5=0;
						num3--;
					}
				}
				else
				{
					if(num4<b[num3]-num5)
					{
						
						num5=num4;
						ans+=num4;
						num4=0;
					}
					else
					{
						
						ans+=b[num3]-num5;
						num4-=b[num3]-num5;
						num5=0;
						num3--;
					}
				}
			}
		}
		cout<<ans<<'\n'; 
	}
	
	
	return 0;
}
