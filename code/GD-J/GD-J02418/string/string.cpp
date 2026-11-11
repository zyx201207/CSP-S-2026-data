#include<bits/stdc++.h>
using namespace std;
string add[21000000];
ifstream fin;
char g_buf[1 << 25];
char*st = g_buf;
inline long long sr()
{
	int f;
	long long x = 0;
	while(*st && (st[0] < '0' ||st[0] > '9'))
	{
		if(st[0] == '-') f = -1;
		st++;
	}
	while((st[0] >= '0' && st[0] <= '9')&&(st[1] >= '0' && st[1] <= '9'))
	{
		x = x * 100 + st[0] * 10 + st[1];
		st+=2;
	}
	if(st[0] >= '0' && st[0] <= '9')
	{
		x = x * 10 + st[0];
		st++;
	}
	return f * x;
}
int main()
{
	fin.open("string.in",ios::in);
	fin.read(g_buf,sizeof(g_buf)); 
	ofstream fout;
	fout.open("string.out",ios::out);
	long long n;
	long long a;
	n = sr();
	char s;
	long long t = 0;
	for(long long i = 0;i < n;i++)
	{
		a = sr();
		s = sr();
		for(long long j = 0;j < a;j++)
		{
			add[t] = s;
			t++;
		}
	}
	long long cnt = 0;
	for(long long i = 0;i < t / 2 + 1;i++)
	{
		if(!(add[i] == add[t - i - 1]))
		{
			cnt++;
			add[t - i - 1] = add[i];
		}
	}
	fout<<cnt;
	return 0;
}
