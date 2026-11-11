#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	if(m==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max=12;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]|a[j]>max)
			{
				a[i]|a[j];
			}
		}
	}
	cout<<max;
	return 0;
}
