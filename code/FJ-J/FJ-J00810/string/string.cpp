#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long s[200005]; 
char c[200005];
map<char,long long>m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long l=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		l+=a[i];
		s[i]=s[i-1]+a[i];
		m[c[i]]+=a[i];
	}
	long long ans=0;
	if(!(l%2))
	{
		for(int i='a';i<='z';i++) ans=max(ans,m[i]);
		cout << l-ans;
	}
	else
	{
		long long mid=l/2+1;
		string s;
		s.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++) s+=c[i];
		}
		for(int i=1;i<mid;i++)
		{
			if(s[mid-i-1]!=s[mid+i-1]) ans++;
		}
		cout << ans;
	}
	return 0;
}

