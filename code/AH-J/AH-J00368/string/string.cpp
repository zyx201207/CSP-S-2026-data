#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node
{
	long long s;
	char t;
}a[N];
long long n,cnt;
string d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int i,j;
	bool t=0;
	for(i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
		if(i!=1&&a[i].t!=a[i-1].t)
			t=1;
		for(j=1;j<=a[i].s;j++)
		{
			d+=a[i].t;
		}
	}
	if(t==0)
	{
		cout<<0;
		exit(0);
	}
	long long l=d.size(),mid=(l+1)/2;
	for(i=0;i<mid;i++)
	{
		if(d[i]!=d[l-i-1])
			cnt++;
	}
	cout<<cnt;
}
//Trick||Treat!
