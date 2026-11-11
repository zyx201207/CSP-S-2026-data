#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m=0,l,p[200005],cnt=0;
char a[200005];
vector<int> v;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;v.push_back(0);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x>>a[i];
		m+=x;p[i]=p[i-1]+x;
		v.push_back(p[i]);
	}
	for(int i=1;i<=n;i++)
	{
		v.push_back(m-p[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	l=v.size()-1;
	
	//for(int i=0;i<=l;i++) cout<<v[i]<<" ";cout<<"\n";
	
	for(int i=1;i<=l-i;i++)
	{
		int j=l-i;
		//cout<<i<<" "<<j<<" ";
		int x=lower_bound(p+1,p+n+1,v[i])-p,y=upper_bound(p+1,p+n+1,v[j])-p;
		//cout<<x<<" "<<y<<"\n";
		if(a[x]!=a[y]) cnt+=v[i]-v[i-1];
	}
	cout<<cnt;
	return 0;
}
