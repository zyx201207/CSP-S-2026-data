#include<bits/stdc++.h>
using namespace std;

long long a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n;
	long long m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	int mid;
	int ans=0;
	long long bu;
	
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n-l+1;i++)
		{
			mid=(i*2+l-1)/2;
			bu=0;
			for(int j=i;j<=i+l-1;j++) bu+=abs(a[mid]-a[j]);
			
			if(bu<=m) ans=max(l,ans);
		}
	
	cout<<ans;
	
	return 0;
}
