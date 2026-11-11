#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char y;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	if(n>2){
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		for(int i=1;i<=n/2;i++)
		{
			int k=n-i+1;
			if(a[i].y!=a[k].y)
			{
			sum+=max(a[i].x,a[k].x);
			}
		}
		cout<<sum;
	}
	if(n==1){
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		cout<<0;
		return 0;
	}
	if(n==2){
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		if(a[1].y==a[2].y)
		{
			cout<<0;
			return 0;
		}
		if(a[1].x<a[2].x)
		{
			cout<<a[1].x;
			return 0;
		}
		else {
			cout<<a[2].x;
			return 0;
		}
	}
	return 0;
}