//GZ-J00009 观山湖区铭苑中学 吴金源 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int maxans=INT_MIN;
int sum=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			maxans=max(maxans,a[i]&a[j]);
	cout<<maxans<<endl;
	return 0;
} 
