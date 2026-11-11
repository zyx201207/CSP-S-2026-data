#include<bits/stdc++.h>
using namespace std;
int a[200010],vis[200010]={1};
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,a[i]);
	}
	cout<<maxn
}
