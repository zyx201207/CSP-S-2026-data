#include<bits/stdc++.h>
using namespace std;
string s;
struct hw{
	long long num;
	string le;
}a[200001];
int n;
long long k=0,ans=0,b=0;;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].le;
		for(k;k<b+a[i].num;k++)
		{
			s[k]=a[i].le[0];	
		}
		b=k;
	}
	k/=2;
	for(int i=0;i<k;i++)
	{
		if(s[i]!=s[b-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
