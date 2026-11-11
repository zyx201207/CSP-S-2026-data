#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char> > str(n+1);
	int length=0;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].first>>str[i].second;
		length+=str[i].first;
	}
	int ans=0;
	int left=str[1].first,right=str[n].first;
	int i=1,j=n;
	while(i<j)
	{
		int m=min(left,right);
		if(str[i].second!=str[j].second)
			ans+=m;
		left-=m; right-=m;
		if(left==0)
			left+=str[++i].first;
		if(right==0)
			right+=str[--j].first;
	}
	cout<<ans<<endl;
	return 0;
}
