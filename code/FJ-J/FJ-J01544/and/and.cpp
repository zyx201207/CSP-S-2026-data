#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string s[200005];
long long ss[50]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
long long t[50]={0};
long long as[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
string er(long long n)
{
	long long i;
	string s="";
	while(n>0)
	{
		s+=n%2+'0';
		n=n/2;
	}
	string s1="";
	for(i=s.size()-1;i>=0;i--)
	{
		s1+=s[i];
	}
	return s1;
}
long long shi(string s)
{
	long long i,j=1,ans=0;
	for(i=s.size()-1;i>=0;i--)
	{
		ans+=(s[i]-'0')*j;
		j*=2;
	}
	return ans;
}
string And(string a,string b)
{
	long long i;
	string s="";
	for(i=0;i<min(a.size(),b.size());i++)
	{
		if(a[i]=='1' and b[i]=='1')
		{
			s+='1';
			t[i]++;
		}
		else
			s+='0';
	}
	return s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j,n,m,ma=0;
	bool A1=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=er(a[i]);
		ma=max(ma,a[i]);
		bool A=0;
		for(j=1;j<=20;j++)
		{
			if(a[i]==ss[i]-1)
			{
				A==1;
				break;
			}
		}
		if(A==0)
			A1=0;
	}
	if(m==1)
		cout<<ma;
	else
	if(n==m)
	{
		string ans;
		ans=And(s[1],s[2]); 
		for(i=3;i<=n;i++)
			ans=And(ans,s[3]);
		cout<<shi(ans);
	}
	else
	if(A1==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	return 0;
}