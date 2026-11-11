#include<bits/stdc++.h>

#define int long long

using namespace std;

string c1, s1, c2, s2;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2)
	{
		cout << "0000";
	}
	else
	{
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout << 1;
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
			{
				cout << 1;
				if (s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1)
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << "00";
			}
		}
		else
		{
			cout << "000";
		}
	}
	return 0;
}
/*
我得到了惩罚
戒了烟我不习惯
没有你我怎么办
三年零一个礼拜
才学会怎么忍耐
你给过我的伤害
是没有一句责怪
戒了烟染上悲伤
我也不舍 
*/ 
