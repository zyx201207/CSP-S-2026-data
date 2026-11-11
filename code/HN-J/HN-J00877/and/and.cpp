#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[200020];
ll two[35];
long long sum;
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=1;i<=m;i++)
		sum&=a[i];
	cout<<sum;
	return 0;
}
