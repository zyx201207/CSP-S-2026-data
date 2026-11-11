#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],num;
int cmp(int a,int b)
{
	return a>b;
}
int ands(int q,int w)
{
	int d=0;
	int qa=0;
	while(q>0)
	{
		long long p=1,aaaa[1000000];
		a[p]=q%2;
		p++;
		q/=2;
		for(int i=1;i<=p;i++)qa+=aaaa[i];
	}
	cout<<qa<<endl;
	int wa=0;
	while(w>0)
	{
		long long p=1,aaaa[100000];
		a[p]=q%2;
		p++;
		q/=2;
		for(int i=1,e=1;i<=p;i++,e*=10)qa+=aaaa[i]*e;
	}
	cout<<wa<<endl;
	if(qa<wa)
	{
		swap(qa,wa);
	}
	while(qa>0)
	{
		int p=1;
		if(qa%10==1&&wa%10==1)
			d+=1*p;
		p*=10;
		qa/=10;
		wa/=10;
	}
	return d;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	num=ands(a[1],a[2]);
	if(m==1)
		cout<<a[1];
	else if(m==2)
		cout<<num;
	else
	{
		for(int i=3;i<=m;i++)num=ands(num,a[i]);
		cout<<num;
	}
	return 0;
}
