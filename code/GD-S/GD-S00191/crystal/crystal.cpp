//过样例1-3，样例4输出 313324 / 正解 315275
#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],b[500010],c[500010];
unsigned long long m;
int ma;
int i,j;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	long long sum=0;
	for(i=1,j=2;i<=n;j++)
	{
		if(j>n)break;
		sum+=b[j]*(j-i);
		if(sum>m)
		{
			ma=max(ma,j-i);
			sum-=c[j]-c[i-1];
			i++,j=i;
		}
	}
	cout<<max(ma,j-i); 
	return 0;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 1
5 4 1 1


都是OIer，我原本没想被单调队列
 
*/
