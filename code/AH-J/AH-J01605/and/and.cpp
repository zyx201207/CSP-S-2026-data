#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
struct node
{
	long long x;
	int f;
}a[N];
int k=1;
void check(long long x)
{
	while(x!=0)
	{
		if(x%2==1) a[k].f++;
		x/=2;
	}
	k++;
}
bool cmp(node a,node b)
{
	if(a.f==b.f) return a.x<b.x;
	return a.f<b.f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		check(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	long long x=a[n].x;
	for(int i=n-1;i>=n-m+1;i--)
	{
		x=x&a[i].x;
	}
	cout<<x;
	return 0;
}
