#include<bits/stdc++.h>
struct seat
{
	int chexiang = 0;
	int pai = 0;
	bool ce = false;
	int zimu = 0;
};
char s[5] = {'\0'};
char ans[5] = {'\0','0','0','0','0'};
int read(char []);
int pand(char);
void output();
seat a,b;
int main()
{
	std::freopen(&"travel.in"[0],&"r"[0],stdin);
	std::freopen(&"travel.out"[0],&"w"[0],stdout);
	std::scanf(&"%s"[0],&s[0]);
	a.chexiang = read(s);
	std::scanf(&"%s"[0],&s[0]);
	a.pai = read(s);
	a.zimu = pand(s[2]);
	if(a.zimu > 4)
	{
		a.ce = true;
	}
	std::scanf(&"%s"[0],&s[0]);
	b.chexiang = read(s);
	std::scanf(&"%s"[0],&s[0]);
	b.pai = read(s);
	b.zimu = pand(s[2]);
	if(b.zimu > 4)
	{
		b.ce = true;
	}
	output();
	std::printf(&"%s"[0],&ans[1]);
	return 0;
}
int read(char s[])
{
	int t = 0;
	for(int i = 0;i < 2;i = i + 1)
	{
		int g = (int)(s[i] - '0');
		t = t * 10 + g;
	}
	return t;
}
int pand(char c)
{
	if(c == 'A')
	{
		return 1;
	}
	if(c == 'B')
	{
		return 2;
	}
	if(c == 'C')
	{
		return 3;
	}
	if(c == 'D')
	{
		return 5;
	}
	return 6;
}
void output()
{
	if(a.chexiang == b.chexiang)
	{
		ans[1] = '1';
		if(a.pai == b.pai)
		{
			ans[2] = '1';
			if(a.ce == b.ce)
			{
				ans[3] = '1';
				if(std::abs(a.zimu - b.zimu) == 1)
				{
					ans[4] = '1';
				}
			}
		}
	}
	return;
}
