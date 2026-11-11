#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],l=0;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(l<=a[i])
		{
			l=a[i];
		}
	}
	cout<<l;
	return 0;
} 
