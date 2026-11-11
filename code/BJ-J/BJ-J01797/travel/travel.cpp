/*
小 R 和小 X 准备坐高铁出门旅游。他们买了两张二等座车票,车票上写着各自的
车厢号和座位号。两人希望座位相邻,这样旅途中可以坐在一起。
他们乘坐的列车由 17 节车厢组成,车厢编号是 01 到 17。其中,01 和 16 号车厢
是一等座车厢,其余车厢是二等座车厢。两人买的都是二等座车票,座位都在二等座车
厢中。每节二等座车厢共有 18 排,每排有 5 个座位。座位号由两位排号和一位大写字
母组成,例如 03C 表示第 3 排 C 座。每一排的座位按照从左到右的顺序排列,座位字
母依次是 A、B、C、D、F,其中 C 座与 D 座之间是过道,即每排过道左侧的座位序列
是 A、B、C,右侧是 D、F。以下是一节二等座车厢的座位示意图:
两个座位相邻,当且仅当在同一节车厢的同一排,位于过道的同一侧,且在该侧的
座位序列中相邻。
你需要帮助小 R 依次判断:
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/
#include "bits/stdc++.h"
using namespace std;
pair<int, int> a[3] = {{'A', 'B'}, {'B', 'C'}, {'D', 'F'}};
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string t1, s1, t2, s2;
	cin >> t1 >> s1 >> t2 >> s2;
	int m1 = s1[0] * 10 + s1[1], m2 = s2[0] * 10 + s2[1];
	char c1 = s1[2], c2 = s2[2];
	if(t1 == t2)
	{
		cout << "1";
		if(m1 == m2)
		{
			cout << "1";
			if((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D'))
			{
				cout << "1";
				bool f = 0;
				for(int i = 0;i <= 2;i++)
				{
					if((c1 == a[i].first && c2 == a[i].second) || (c1 == a[i].second && c2 == a[i].first))
					{
						f = 1;
						break;
					}
				}
				if(f)
				{
					cout << "1";
				}else
				{
					cout << "0";
				}
			}else
			{
				cout << "00";
			}
		}else
		{
			cout << "000";
		}
	}else
	{
		cout << "0000";
	}
	//cout << "Hello, World!";
	return 0;
}
