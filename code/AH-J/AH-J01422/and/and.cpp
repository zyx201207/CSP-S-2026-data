#include<bits/stdc++.h>
using namespace std;
int a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mx=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			if(a[j]&a[j+1]>mx)
			{
				mx=a[j]&a[j+1];
			}
		}
	}
	cout<<mx;
	return 0;
}
