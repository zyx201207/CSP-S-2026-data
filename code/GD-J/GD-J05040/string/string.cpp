#include <bits/stdc++.h>
using namespace std;
const int maxn=200005; 
int n=0;
long long sum=0;
struct node
{
	int num;
	char val;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	node a[n];
	long long lazyf=0,lazye=0;
	int fn=0;
	int en=n;
	long long f=0,e=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].num>>a[i].val;
		e+=a[i].num;
	}
	while (f<e)
	{
		if((f-lazyf)>=a[fn].num) 
		{
			fn++;
			lazyf+=a[fn].num;
		}
		if((e-lazye)>=a[en].num) 
		{	
			en--;
			lazye+=a[en].num;
		}
		if(a[fn].val!=a[en].val) sum++;
		f++;
		e--;
	}
	cout<<sum<<endl;
	return 0;
} 
