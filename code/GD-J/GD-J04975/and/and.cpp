#include <bits/stdc++.h>
using namespace std;
int n,maxz,m,a[200004],b[200004],c[200004];
int change(int x)
{
	int m=0,k=1,cnt=1;
	while(x>0)
	{
		m+=(x%2)*k;
		if (x%2==1){
			c[cnt]++;
		}
		k*=10;
		x/=2;
		cnt++;
	}
	return m;
}
int check(int x)
{
	int ans;
	while(x>=10){
		ans++;
		x/=10;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=-9;
	for (int i = 1;i<=n;i++)
	{
		cin>>a[i];
		maxz=max(maxz,a[i]);
		b[i]=change(a[i]);
		maxn=max(maxn,b[i]);
	}
	int l=check(maxn);
	
	if(m==1){
		cout << maxz;
		return 0;
	}
	return 0;
}
