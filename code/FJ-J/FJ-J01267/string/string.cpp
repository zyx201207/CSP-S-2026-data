#include<bits/stdc++.h>
using namespace std;

int n,a[500005];
char c[500005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	long long ans=0;
	while(l!=r)
	{
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		int num=min(a[l],a[r]);
		a[l]-=num;
		a[r]-=num;
		if(!a[l]) l++;
		else r--; 
	}
	cout<<ans;
	return 0;
} 
