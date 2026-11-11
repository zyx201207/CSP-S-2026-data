#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
const long long N=2e5+10;
long long n,m,len=-1,p,ans;
vector<long long> a(N,0);
vector<string> s(N,"");
queue<long long> q;
string change(long long n)
{
	if(n==0) return "0";
	string t="";
	while(n!=0)
	{
		char ch=n%2+'0';
		t=ch+t;
		n/=2;
	}
	return t;
}
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a.begin()+1,a.begin()+n+1,cmp);
	for(long long i=1;i<=n;i++) s[i]=change(a[i]);
	for(long long i=1;i<=n;i++) q.push(i);
	for(long long i=1;i<=n;i++)
	{
		long long l=s[i].size();
		len=max(len,l);
	}
	for(long long i=1;i<=n;i++)
	{
		while(s[i].size()<len) s[i]='0'+s[i];
	}
	p=n;
	for(long long i=0;i<len;i++)
	{
		long long cnt=0,cc=0;
		for(long long j=1;j<=p;j++)
		{
			long long f=q.front();
			q.pop();
			q.push(f);
			if(s[f][i]=='1') cnt++;
		}
		if(cnt>=m)
		{
			for(long long j=1;j<=p;j++)
			{
				long long f=q.front();
				q.pop();
				if(s[f][i]=='1') q.push(f);
				else cc++;
			}
		}
		p-=cc;
	}
	for(long long i=1;i<=m;i++)
	{
		long long f=q.front();
		q.pop();
		if(i==1) ans=a[f];
		else ans&=a[f];
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12

5 2
0 1 2 3 4
*/
