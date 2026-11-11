#include<bits/stdc++.h>
using namespace std;
long long a[200002];
vector<long long> s[100];
long long mi[50];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	mi[0]=1;
	for(long long i=1;i<=40;i++)
	mi[i]=mi[i-1]*2;
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	cin>>a[i],s[1].push_back(a[i]) ;
	long long pp=1;
	long long ans=0;
	for(long long i=30;i>=0;i--)
	{
		for(long long j=0;j<s[pp].size();j++)
		{
			if((s[pp][j]&mi[i])!=0){
				s[pp+1].push_back(s[pp][j]);
			}
		}
		if(s[pp+1].size()>=m)
		{
			pp=pp+1;
			ans+=mi[i];
		}
		else
		s[pp+1].clear();
	}
	cout<<ans;
	return 0;
}
