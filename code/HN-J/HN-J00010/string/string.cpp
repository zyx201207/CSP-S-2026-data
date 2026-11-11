#include<bits/stdc++.h> 
using namespace std;
char s[1000000005];
int main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,cnt=0,len=1;
	char w;
	cin >> n;
	for(int m=1;m<=n;m++)
	{
		cin >> i >> w;
		len+=i;
		for(int j=len;j<=len+i;j++)
		{
			s[j]=w;
		}
	}
	int r=n;
	for(int l=1;l<=(len/2);l++)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		r--;
	}
	cout << cnt;
	return 0;
}
