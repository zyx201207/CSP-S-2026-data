#include<bits/stdc++.h>
using namespace std;
int a[200005][35],mxk=-1;
queue<int> v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,k=0;
		cin>>x;
		a[i][0]=x;
		while(x)
		{
			a[i][++k]=x%2;
			x/=2;
		}
		mxk=max(mxk,k);
		v.push(i);
	}
	for(int i=mxk;i>=1;i--)
	{
		queue<int> v1,vv=v;
		while(vv.size())
		{
			if(a[vv.front()][i]==1) v1.push(vv.front());
			vv.pop();
		}
		if(v1.size()>=m) v=v1;
		if(v.size()==m) break;
	}
	int ans=a[v.front()][0];
	v.pop();
	for(int i=2;i<=m;i++)
	{
		ans=(ans&a[v.front()][0]);
		v.pop();
	}
	cout<<ans;
	return 0;
}
