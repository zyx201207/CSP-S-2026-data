#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	d=a[1];
	for(int i=1;i<=m;i++)
	{
		d=a[i]&d;
	}
	cout<<d;
	return 0;
} 
