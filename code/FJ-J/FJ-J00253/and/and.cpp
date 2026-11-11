#include<bits/stdc++.h>
using namespace std;
int n,m,t[30];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long l[250000];
	long long q=0,p=1;
	cin>>n>>m;
	for(int a=0;a<n;a++)
		cin>>l[a];
	sort(l,l+n,cmp);
	for(int a=0;a<m;a++)
	{
		int s=0;
		while(l[a])
		{
			t[s]+=l[a]%2;
			l[a]/=2;
			s++;
		}
	}
	for(int a=0;a<30;a++)
	{
		if(t[a]==m) q+=p;
		p*=2;
	}
	cout<<q;
	return 0;
}