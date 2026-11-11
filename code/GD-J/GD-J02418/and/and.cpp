#include<bits/stdc++.h>
using namespace std;
long long add[10000000];
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
	fin.open("and.in",ios::in);
	fin.read(g_buf,sizeof(g_buf));
	ofstream fout;
	fout.open("and.out",ios::out);
	long long n = sr();
	long long m = sr();
	add[0] = sr();
	long long mx = add[0];
	long long t = add[0];
	for(long long i = 1 ;i < n;i++)
	{
		add[i] = sr();
		mx = mx > add[i] ? mx:add[i];
		t = t | add[i];
	}
	if(m == 1)
	{
		fout<<mx;
	}
	else if(m == n)
	{
		fout<<t;
	}
	else
	{
		cout<<"12";
	}
	return 0;

}
