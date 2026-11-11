#include<bits/stdc++.h>
using namespace std;
int n,m,a[514514],ans[514514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{	ans[a[i]]=i;	}	
	for(int i=1;i<=m;i++)
	{	cout<<n-ans[i]+1<<' ';	}
	return 0;
}
