#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0,ans=0;
vector<long long> sz;
vector<bool> bg;
void fd(int k)
{
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(!bg[i])continue;
		if((sz[i]/k)%2==1)
		{
			v.push_back(i);
		}
	}
	if(v.size()>=m)
	{
		for(int i=0;i<n;i++)bg[i]=0;
		for(int i=0;i<v.size();i++)bg[v[i]]=1;
		ans+=k;
	}
	if(k==1)return;
	fd(k/2);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sz.resize(n);
	bg.resize(n,1);
	for(int i=0;i<n;i++)
	{
		cin>>sz[i];
		maxn=max(sz[i],maxn);
	}
	long long k=1;
	while(k<=maxn/2)
	{
		k*=2;
	}
	fd(k);
	cout<<ans;
	return 0;
}
