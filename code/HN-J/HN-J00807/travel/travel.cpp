#include <bits/stdc++.h>
using namespace std;

struct train{
	string c;
	string s;
}; 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	train a,b;
	char ans[4] = {' ',' ',' ',' '},sa,sb,seat_n[3] = {'A','B','C'},seat_m[2] = {'D','F'};
	int seata=0,seatb=0,cnt=0;
	cin >> a.c >> a.s >> b.c >> b.s;
	if(a.c == b.c)
	{
		ans[0] = '1';
	}
	else
	{
		ans[0] = '0';
		ans[1] = '0';
		ans[2] = '0';
		ans[3] = '0';
		for(int i = 0;i<=3;i++)
		{
			cout << ans[i];
		}
		return 0;
	}
	for(int i=0;i<2;i++)
	{
		if(a.s[i] == b.s[i])
		{
			ans[1] = '1';
		}
		else
		{
			ans[1] = '0';
			ans[2] = '0';
			ans[3] = '0';
			for(int i = 0;i<=3;i++)
			{
				cout << ans[i];
			}
			return 0;
		}
	}
	sa = a.s[2];
	sb = b.s[2];
	if((sa == 'A' || sa == 'B'|| sa == 'C') && (sb == 'A' || sb == 'B' || sb == 'C')&& sa != sb){
		seata++;
	}
	else if((sa == 'D' || sa == 'F')&& (sb == 'D' || sb == 'F') && sa != sb){
		seata++;
	}
	if(seata != 0)
	{
		ans[2] = '1';
	}
	else
	{
		ans[2] = '0';
		ans[3] = '0';
		for(int i = 0;i<=3;i++)
		{
			cout << ans[i];
		}
		return 0;
	}
	if(sa -1 == sb || sa + 1 == sb)
	{
		ans[3] = '1';
	}
	else
	{
		ans[3] = '0';
	}
	for(int i = 0;i<=3;i++)
	{
		cout << ans[i];
	}
	return 0;
}

