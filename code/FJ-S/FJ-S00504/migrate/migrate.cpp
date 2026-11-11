#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		unordered_set<long long>b;
		long long s=0;
		for(int i=0;i<n;i++)
			cin>>x[i],
			b.insert(x[i]);
		for(int i=0;i<n;i++)
			if(b.count(x[i]-2*d+1)&&b.count(x[i]-d)&&b.count(x[i]-d+1))
				s++;
		cout<<s<<"\n";
	}
	return 0;
}
