#include<bits/stdc++.h>
using namespace std;
struct p
{
	int x,how;
};
int n,m,ans,ans2;
vector<p>maxx;
bool o(p a1,p a2)
{
	return a1.how>a2.how;
}
bool o2(p a1,p a2)
{
	return a1.x>a2.x;
}
int howw(int x)
{
	int sum=0;
	for(;x>0;x=x&(x-1))
	{
		++sum;
	}
	return sum;
}
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		maxx.push_back({x,howw(x)});
	}
	sort(maxx.begin(),maxx.end(),o);
	ans=maxx[0].x;
	for(int i=1;i<m;i++)
	{
		ans=ans&maxx[i].x;
	}
	sort(maxx.begin(),maxx.end(),o2);
	ans2=maxx[0].x;
	for(int i=1;i<m;i++)
	{
		ans2=ans2&maxx[i].x;
	}
	cout<<max(ans,ans2);
	return 0;
}

