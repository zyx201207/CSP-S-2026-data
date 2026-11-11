//GZ-S00012 观山湖区铭苑中学 吴金源 
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int n,m;
int c=1;
int ans=INT_MIN;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		a[i]++;
		sum=max(ans,a[i]+a[i+1]);
		if(sum!=ans)
			c++;
		ans=sum;
	}
	cout<<c<<endl;
	return 0;
}
