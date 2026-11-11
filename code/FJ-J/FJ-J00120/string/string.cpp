#include <bits/stdc++.h>
using namespace std;
long long n,sum,num,sum2,tou,wei;
struct node{
	long long shu;
	char zi;
}a[300000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i].shu >> a[i].zi;
		sum+=a[i].shu;
	}
	sum2=sum/2;
	tou=1;
	wei=n;
	while(sum2>0&&tou<=wei)
	{
		long long minnn=min(a[tou].shu,a[wei].shu);
		if(a[tou].zi==a[wei].zi)
		{
			sum2-=minnn;
			a[tou].shu-=minnn;
			a[wei].shu-=minnn;
			if (a[tou].shu==0)
			{
				tou++;
			}
			else
			{
				wei--;
			}
		}
		else 
		{
			sum2-=minnn;
			num+=minnn;
			a[tou].shu-=minnn;
			a[wei].shu-=minnn;
			
			if (a[tou].shu==0)
			{
				tou++;
			}
			else
			{
				wei--;
			}
		}
	}
	cout << num;
	return 0;
}
