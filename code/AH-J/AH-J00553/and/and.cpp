#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	if(n==m)
	{
		ans=a[1];
		for(int i=1;i<=n;i++)
		{
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
	{
		int t=0;
		int ans_k=0;
		bool f=true;
		for(int j=1;j<=n;j++)
		{
			int k=i>>(j-1);
			if((k&1)==1)
			{
				t++;
				if(f)
				{
					ans_k=a[n-j+1];
					f=false;
				}
				else
				{
					ans_k=(ans_k&a[n-j]);
				}

			}
			if(t>m)
			{
				ans_k=0;
				break;
			}
		}
		if(t==m)
		{
			ans=max(ans,ans_k);
		}
	}
	cout<<ans;
	return 0;
}

