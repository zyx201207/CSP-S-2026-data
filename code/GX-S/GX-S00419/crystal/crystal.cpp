#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[500010],ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int num1=0,num2=0;
		for(int j=i;j<=n;j++)
		{
			if(j==i) {num1++;num2+=a[j];ans=max(num1,ans);}
			else 
			{
				num1++;
				num2+=a[j];
				for(int k=0;k<=m;k++)
					if((k+num2)%num1==0&&(k+num2)/num1>=a[j]) {ans=max(ans,num1);}
			}
		}
	}
	cout<<ans;
	return 0;
}
