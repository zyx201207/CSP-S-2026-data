#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<long long>a(n+1),len(n+1);
	len[0]=0;
	vector<char>c(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i],len[i]=len[i-1]+a[i];
	long long ans=0;
	long long i=1,l=1,r=n;
	while(l<r)
	{
		if(len[l]<i)l++;
		if(len[n]-len[r-1]<i)r--;
		if(l>=r)break;
		if(c[l]!=c[r])
		{
			// cout<<min(len[l],len[n]-len[r-1])<<'\n';			
			ans+=min(len[l],len[n]-len[r-1])-i+1;
			// cout<<ans<<'\n';
			i=min(len[l],len[n]-len[r-1])+1;
		}
		else
			i=min(len[l],len[n]-len[r-1])+1;
		// cout<<l<<' '<<r<<' '<<i<<'\n';
	}
	// for(int i=1;i<=n;i++)cout<<len[i]<<' ';
	cout<<ans;
	return 0;
}