#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,a[200001];
long long s(int x,int y,int sum)
{
	if(y>=m)return sum;
	if(x>n)return 0;
	return max(s(x+1,y+1,sum & a[x+1]),s(x+1,y,sum));
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,s(i,1,a[i]));
	}
	cout<<maxx;
	return 0;
}
