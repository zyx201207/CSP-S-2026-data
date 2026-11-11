#include <bits/stdc++.h>
using namespace std;


int pd(string s)
{
	string num1;
	for(int m=s.size();m>=1;m--)
	{
		num1+= s[m-1];
	}
	if(num1==s)
	{
		return 1;
	}
	else return 0;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,cnt=0;
	string num,e;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >>k>>e;
		for(int j=1;j<=k;j++) num += e;
	}
	if(pd(num)==0)
	{
		for(int m=0;m<=num.size()/2-1;m++)
		{
			if(num[num.size()-m]!=num[m])
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
