#include<bits/stdc++.h>
using namespace std;
long long b[20005];
char c[20005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt = 0 , cnt1 = 0 , cnt2 = 0;
	long long num = 0;
	cin >> n;
	for(int i = 1; i <= n;i++)
	{
		cin >> b[i] >> c[i];
		cnt+=b[i];
	}
	string st , st1;
//	int q1 = 1, q2 = n;
//	while(q1<q2)
//	{
//		if(b[q1] == 0)q1++;
//		if(b[q2] == 0)q2++;
//		if(c[q1]!=c[q2])num++;
//		b[q1]--;
//		b[q2]--;
//	}
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1; j <= b[i];j++)
		{
			if(cnt1<=cnt/2)st+=c[i];
		}
		cnt1++;
	}
	for(int i = n;i >= 1;i--)
	{
		for(int j = 1; j <= b[i];j++)
		{
			if(cnt2<=cnt/2)st1+=c[i];
		}
		cnt2++;
	}
	for(int i = 0; i < cnt/2;i++)
	{
		if(st[i] != st1[i])num++;
	}
	if(num<=cnt/2-num)
	{
		cout << (cnt/2-num);
	}
	else
	{
		cout << num;
	}
	return 0;
}
