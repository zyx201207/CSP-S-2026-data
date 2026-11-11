#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
char b[200005],d[200005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		c[i]=a[i];
		d[i]=b[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		//cout<<l<<" "<<r<<endl;
		int K=min(a[l],a[r]);
		a[l]-=K;
		if(l!=r)
		{
			a[r]-=K;
		}
		if(b[l]!=b[r]&&l!=r)
		{
			ans+=K;
		}
		if(a[l]==0)
		{
			l++;
		}
		if(a[r]==0)
		{
			r--;
		}
	}
	cout<<ans;
 } 
