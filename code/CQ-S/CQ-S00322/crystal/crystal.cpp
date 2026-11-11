#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int M=5e5+5;
int n,ans=1,ans1=1;
long long m,a[M],b[M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	int j=1;
	while(1)
	{
		long long m1=m;
		bool flag=true;
		ans=1;
		for(int i=j;i<n;i++)
		{
			long long k=b[i];
			long long p=(i-j+1)*k;
			if(m1>=p)
			{
				m1-=p;
				ans+=1;
			}
			else
			{
				j=i;
				flag=false;
				break;
			}
		}
		ans1=max(ans,ans1);
		if(j==n||flag) break;
		j++;
	}
	cout<<ans1<<endl;
}
