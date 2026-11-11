#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n;
	cin >> n;
	long long a,cnt=0,_cnt=0;
	char c[10000],b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		for(int j=cnt;j<a+cnt;j++)
		{
			c[j]=b;
		}
		cnt+=a;
	}
	for(int i=0;i<cnt/2;i++)
	{
		if(c[i]!=c[cnt-i-1]) _cnt++;
	}
	cout << _cnt;
	return 0;
}
