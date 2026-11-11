#include<bits/stdc++.h>
using namespace std;
struct aaa
{
	long long cd;
	long long l,r;
	char w;
};
aaa qj[100005];
long long n,m;
char nb[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	long long i,j,h;
	char f;
	for(i=1;i<=m;i++)
	{
		cin>>h>>f;
		qj[i].l=n+1;
		qj[i].r=n+h;
		qj[i].w=f;
		qj[i].cd=h;
		for(j=qj[i].l;j<=qj[i].r;j++)
		{
			nb[j]=f;
		}
		n+=h;
	}
	for(i=1;i<=n;i++)
	{
		cout<<nb[i]<<' ';
	}
	cout<<'\n';
	long long ans=0;
	for(i=1;i<=n/2;i++)
	{
		if(nb[i]==nb[n-i+1])
		{
			ans++;
		}
	}
	cout<<n/2-ans;
	return 0;
}
