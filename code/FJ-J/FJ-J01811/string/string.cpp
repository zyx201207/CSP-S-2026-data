#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long ans=0,h,sum1=0,sum2=0,l=0;
long long n,cnt=0,d;
string s;
long long x;
char y;	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(0);
	cin>>n;
	cin>>x;
	cin>>y;
	for(long long i=1;i<=x;i++)
	{
		s+=y;
	}
	if(n%2==0)
	{
		d=n/2;
	}
	else
	{
		d=n/2+1;
	}
	
	for(long long i=2;i<=n;i++)
	{
		cin>>x;
		cin>>y;
		for(long long j=1;j<=x;j++)
		{
			s+=y;
		}
		if(y-'0'==s[i-1]-'0')
		{
			cnt++;
		}
		if(l!=d)
		{
			sum1+=x;
			l++;
		}
		else
		{
			sum2+=x;
		}
	}

	if(cnt==n-1)
	{
		cout<<0;
		return 0;
	}
	if(cnt==d&&sum1==sum2)
	{
		cout<<sum1;
		return 0;
	}
	if(s.size()%2==0)
	{
		h=s.size()/2;
	}
	else
	{
		h=s.size()/2+1;
	}
	for(long long i=0;i<h;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
