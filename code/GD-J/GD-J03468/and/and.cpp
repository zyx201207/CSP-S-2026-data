#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],maxn=INT_MIN;
int ad(int a,int b)
{
	return a & b;
}
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n-1;i++) for(int j=i+1;j<=n;j++) maxn=max(maxn,ad(a[i],a[j]));
	cout<<maxn;
	return 0;
}

