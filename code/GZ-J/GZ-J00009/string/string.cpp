//GZ-J00009 观山湖区铭苑中学 吴金源 
#include<bits/stdc++.h>
using namespace std;
char a[20000005];
int sum=0;
bool ifhuiwen()
{
	for(int l=1,r=sum;l<=sum;l++,r--)
		if(a[l]!=a[r])
			return 0;
	return 1;
}
int sethuiwen()
{
	int ans=0;
	for(int l=1,r=sum;l<=sum;l++,r--)
		if(a[l]!=a[r])
		{
			a[l]=a[r];
			ans++;
		}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		char s;
		cin>>s;
		for(int j=1;j<=x;j++)
			a[++sum]=s;
	}
	if(ifhuiwen())
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<sethuiwen()<<endl;
	return 0;
} 
