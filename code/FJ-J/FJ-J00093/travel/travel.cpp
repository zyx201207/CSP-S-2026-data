#include <iostream>

using namespace std;

string s1, s2, s3, s4;

inline bool get(char e, char f)
{
	if (e <= 'C' && f <= 'C') return true;
	if (e >= 'D' && f >= 'D') return true;
	return false;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> s1 >> s2 >> s3 >> s4;
	
	int a = 0, b = 0;
	for (auto c : s1)
		a = a * 10 + (c - '0');
	for (auto c : s3)
		b = b * 10 + (c - '0');
	
	int c = 0, d = 0;
	char e = '\0', f = '\0';
	for (int i = 0; i < s2.size(); ++ i )
	{
		if (s2[i] < '0' || s2[i] > '9')
		{
			e = s2[i];
			continue;
		}
		c = c * 10 + (s2[i] - '0');
	}
	for (int i = 0; i < s4.size(); ++ i )
	{
		if (s4[i] < '0' || s4[i] > '9')
		{
			f = s4[i];
			continue;
		}
		d = d * 10 + (s4[i] - '0');
	}
	
	if (e == 'F') e = 'E';
	if (f == 'F') f = 'E';
	if (e > f) swap(e, f);
	
	bool sign1 = (a == b);
	bool sign2 = (sign1 && (c == d));
	bool sign3 = (sign2 && get(e, f));
	bool sign4 = (sign1 && sign2 && sign3 && (f - e) == 1);
	
	int res1 = sign1, res2 = sign2, res3 = sign3, res4 = sign4;
	printf("%d%d%d%d", res1, res2, res3, res4);
	
	return 0;
}
/*
yi£¬mei xiang dao di san ci da CSP-J hui ru ci can lie
T1 shi bi jiao jian dan de, kai chang yi xia jiu gua le
T2 ben yi wei shi yi ge mo ni, da le hen jiu mei guo da yang li 4
fang qi T2, kai le T3
T3 di yi yan shi DP, dan shi DP wu fa you hua, kai shi xiang tan xin
fa xian yi ge fei chang hao wan de xing zhi
da le zheng jie
da gua le
xiu wan hou pao da yang li you RE le
fa xian pai xu de bi jiao han shu chu guo le
hou mian you hua le yi xia bi jiao han shu
xiu le ji ge bug
jiu guo le
ying gai bu hui bu kai long long jian zu zong ba.
T4 kan qi lai hen you gan jue, dan jiu shi mei sha tu po kou
yu shi hui qu xiang T2 de bao li
bi jiao shun, T2 bao li 68pts guo le zui da de yang li,ying gai bu hui gua le ba.
gan jin qu da T4 le. 
T4 ying gai shi [0,32]
300 you mei le
ju li tui yi bu zu 1000days le, jia you ba!xia wu hai you S
luogu:1178294 

du dao de ren hui AK IOI
CCF newbie!
xi wang shao ye ji hui ba wo T2 68pts fang guo qu.
fen lai! fen lai! fen lai!
*/
