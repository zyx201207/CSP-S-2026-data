#include<iostream>
using namespace std;
const int N=2*1e5+10;
unsigned long long a[N];
char c[N];
string s,fs;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(unsigned long long j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(unsigned long long i=s.length()-1;i>=0;i--)
	{
		fs+=s[i];
	}
	if(s==fs)
	{
		cout<<"0";
		return 0;
	}
	if(s.size()%2==0)
	{
		int cnt=0;
		for(unsigned long long i=0;i<s.size();i++)
		{
			if(s[i]!=fs[i])
			{
				cnt++;
			}
		}
		cout<<(cnt/2);
	}else{
		unsigned long long l=s.size();
		unsigned long long mid=(l/2)+1;
		unsigned long long cnt=0;
		for(unsigned long long i=0;i<mid;i++)
		{
			if(s[i]!=fs[i])
			{
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
