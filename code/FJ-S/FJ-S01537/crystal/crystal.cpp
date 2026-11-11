#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000005;
long long n,m,num=1;
long long a[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=1;i<n;i++)
	{
		long long b=m,c=1,cha=a[i]-a[i-c],compare=1;
		if((a[i]-a[i-1])>m) continue;
		b-=(a[i]-a[i-1]);
		compare+=1;
		while((i-c)>=0)
		{
			if((b-cha)>0)
			{
				b-=cha;
				compare+=1;
				c+=1;
				cha=a[i]-a[i-c];
			}
			else break;
		}
		if(num<compare) num=compare;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
