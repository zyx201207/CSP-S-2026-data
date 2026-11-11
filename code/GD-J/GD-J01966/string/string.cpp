#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		char c;
		long long x;
		cin>>x>>c;
		a[i]=x;
		s+=c;
	}
	long long l=0,r=s.size()-1,cnt=0;
	while(l<r)
	{
		long long x=min(a[l],a[r]);
		if(s[l]!=s[r])cnt+=x;
		a[l]-=x;
		a[r]-=x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<cnt;
	return 0;	
} 
