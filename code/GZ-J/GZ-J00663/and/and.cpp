//GZ-J00663 北京师范大学贵阳附属中学 杨梓萱
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,a[N],x;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]&a[j]>a[i]&a[j+1] && j!=i)
				x=a[i]&a[j];
			else if(a[i]&a[j]<a[i]&a[j+1] && j!=i)
				x=a[i]&a[j+1];
		}
	}
	cout<<x;
	return 0;
}
