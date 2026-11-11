#include<bits/stdc++.h>
using namespace std;

long long num;

long long n,cnt;
long long nct[100000];
string sct[1000000];
string s="";
string s2="";

string sq="";
string sh="";

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> nct[i] >> sct[i];
		for(int j=1;j<=nct[i];j++)
		{
			s+=sct[i];
		}
		cnt+=nct[i];
	}
	     
	for(int i=cnt-1;i>=0;i--)
	{
		s2 += s[i];
	}
	if(s2 == s)
	{
		cout << 0;
		return 0;
	}
	if(cnt%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
			sq += s[i];
			sh += s[cnt-1-i];
			if(sq[i]!=sh[i])
				num++;
		}
	}
	else
	{
		for(int i=0;i<=n/2;i++)
		{
			sq += s[i];
			sh += s[cnt-1-i];
			if(sq[i] != sh[i])
				num++;
		}
		
	}
	cout << num;
	return 0;
} 
