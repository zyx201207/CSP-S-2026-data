#include<bits/stdc++.h>
using namespace std;

char str[6000000000];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,num=0,_len,cnt=0;
	char c; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=num;j<a+num;j++)
		{
			str[j]=c;
		}
		num+=a;
	}
	cout<<str;
	_len=floor(num/2);
	for(int i=0;i<_len;i++)
	{
		if(str[i]!=str[num-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
