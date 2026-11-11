#include<bits/stdc++.h>
using namespace std;
int c,t;
int i,j,k;
int a[100005];
int ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		ans=0;
		scanf("%d%d",&n,&d);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			int l=0;
			for(j=i+1;j<n;j++)
			{
				if(a[j]-a[i]<=d)l++;
				else break; 
			}
			if(l<3)ans++;
		}
		cout<<(ans-1)/2;
	}
}
