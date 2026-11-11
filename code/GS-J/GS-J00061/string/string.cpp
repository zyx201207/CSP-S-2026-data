#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
char a;
long long cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    string s="";
    for(long long i=0;i<n;i++)
    {
    	cin >> m >> a;
    	for(long long j=0;j<m;j++)
    	{
    		s+=a;
		}
	}
	long long len=s.size();
	for(long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
