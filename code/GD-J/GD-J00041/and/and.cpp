#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
struct node
{
	int pre;
	string o;
}a[N]; 
string one(int x)
{
	int x2=x;
	string s;
	while(x2)
	{
		if(x2%2==1) s='1'+s;
		else s='0'+s;
		x2/=2;
	}
	return s;
}
bool cmp(node x,node y)
{
	return x.o>y.o;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].pre;
		a[i].o=one(a[i].pre);
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].pre;
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i].pre;
	}
	cout<<ans;
	return 0;
}
