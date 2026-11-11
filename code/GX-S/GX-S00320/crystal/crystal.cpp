#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n;
long long v[N];
unsigned long long m,pre[N],sum[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>v[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)	pre[i]=(unsigned long long)(v[i]-v[i-1]);
	
	int as=0,j=0,i=1;
	for(i=1;i<=n;i++)
	{
		sum[i]=(i-1)*pre[i]+sum[i-1];
		//cout<<sum[i]<<' ';
		if(sum[i]-sum[j]>m || i==n)
		{
			as=max(as,i-j-1);
			//cout<<as<<' '<<i<<' '<<j<<' '<<i-j-1<<endl;
			while(sum[i]-sum[j]>m && j<i)	j++;	
			as=max(as,i-j-1);
		}
	}
	
	cout<<as<<endl;
	return 0;
}
