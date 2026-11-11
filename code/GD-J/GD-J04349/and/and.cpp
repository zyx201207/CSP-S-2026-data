#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200020];
bool b[35][200020];
set<int> s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) 
	{
		s.insert(i);
		cin>>a[i];
		int top=0;
		while(a[i])
		{
			b[top][i]=a[i]&1;
			a[i]>>=1;
			++top;
		}
	}
	int ans=0;
	for(int i=30;i>=0;--i)
	{
		int t=0;
		for(set<int>::iterator it=s.begin();it!=s.end();++it)
		{
			if(b[i][*it]) ++t;
		}
		if(t>=m)
		{
			ans+=(1<<i);
			for(set<int>::iterator it=s.begin();it!=s.end();)
			{
				if(!b[i][*it])
				{
					set<int>::iterator it1=it;
					++it;
					s.erase(it1);
				}
				else ++it;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
