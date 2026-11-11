#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			s=max(s,a[i]&a[j]);
		}
	}
	cout<<s;
	return 0;
}
