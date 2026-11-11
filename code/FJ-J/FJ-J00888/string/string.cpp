#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
pair<int,char>a[200007],b[200007];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	//cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		b[n-i+1]=a[i];
	}
	int ans=0;
	int i=1,j=1;
	while(1)
	{
		int k=min(a[i].first,b[j].first);
		if(a[i].first>b[j].first)
		{
			b[j].first=0;
			a[i].first-=k;
			if(a[i].second!=b[j].second) ans+=k;
			j++;
		}
		else if(a[i].first<b[j].first)
		{
			a[i].first=0;
			b[j].first-=k;
			if(a[i].second!=b[j].second) ans+=k;
			i++;
		}
		else
		{
			a[i].first=0; 
			b[j].first=0;
			if(a[i].second!=b[j].second) ans+=k;
			i++;
			j++;
		}
		if(i>n||j>n) break;
	}
	cout<<ans/2;
	return 0;
}

