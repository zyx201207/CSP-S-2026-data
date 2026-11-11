#include<bits/stdc++.h>
#define N 200005
using namespace std;
long long n,t,ans;
struct stu{
	long long a;
	char c;
}x[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i].a>>x[i].c;
	for(int i=1,j=n;i<=j;)
	{
		if(x[i].a>x[j].a)
		{
			if(x[i].c!=x[j].c) ans+=x[j].a;
			x[i].a-=x[j].a,j--;
		}
		if(x[i].a<x[j].a)
		{
			if(x[i].c!=x[j].c) ans+=x[i].a;
			x[j].a-=x[i].a,i++;
		}
		if(x[i].a==x[j].a)
		{
			if(x[i].c!=x[j].c) ans+=x[i].a;
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
