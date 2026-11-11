#include<bits/stdc++.h>
using namespace std;
priority_queue<int> p; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		p.push(a);
	}
	a=p.top();
	p.pop();
	for(int i=2;i<=m;i++)
	{
		b=p.top();
		p.pop();
		a=a&b;
	}
	cout<<a;
	return 0;
 } 
