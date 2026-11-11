#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
		//cout<<a[i]<<endl;
	}
	sort(a,a+n,cmp);
	int ans = a[0];
	for(int i=1;i<m;i++)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
 } 
