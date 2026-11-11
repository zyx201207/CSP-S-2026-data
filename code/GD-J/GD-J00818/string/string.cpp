#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e6+200;
struct Student{
	long long num;
	char c;
}a[maxn]; 
long long n,ans,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;	
	}
		for(long long i=1,j=n;i<=j;)
		{
			if((a[i].c!=a[j].c)&&a[i].num>=a[j].num)
			{
				ans+=a[j].num;
				a[i].num=a[i].num-a[j].num;
				j--;
			}
			else
			if((a[i].c!=a[j].c)&&a[i].num<=a[j].num)
			{
				ans+=a[i].num;
				a[j].num=a[j].num-a[i].num;
				i++;
			}
			else
			if((a[i].c!=a[j].c)&&a[i].num==a[j].num)
			{
				ans+=a[j].num;
				j--,i++;
			}
			else
			if((a[i].c==a[j].c)&&a[i].num>=a[j].num)
			{
				a[i].num=a[i].num-a[j].num;
				j--;
			}
			else
			if((a[i].c==a[j].c)&&a[i].num<=a[j].num)
			{
				a[j].num=a[j].num-a[i].num;
				i++;
			}
			else
			if((a[i].c==a[j].c)&&a[i].num==a[j].num)
			{
				i++,j--;
			}
		}
		cout<<ans;
}
