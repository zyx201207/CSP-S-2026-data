/*
08:30 开始考试
08:35 开T1
08:55 完成样例并提交
*/
#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool check1(){
	return c1 == c2;
}

bool check2(){
	return s1.substr(0,2) == s2.substr(0,2);
}

bool check3(){
	return ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E'));
}

bool check4(){
	return abs(s1[2] - s2[2]) == 1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	// freopen("travel1.in","r",stdin);
	// freopen("travel1.out","w",stdout);

	// freopen("travel2.in","r",stdin);
	// freopen("travel2.out","w",stdout);

	// freopen("travel3.in","r",stdin);
	// freopen("travel3.out","w",stdout);

	// freopen("travel4.in","r",stdin);
	// freopen("travel4.out","w",stdout);

	// freopen("travel5.in","r",stdin);
	// freopen("travel5.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	cout << (check1()) << (check1() && check2()) << (check1() && check2() && check3()) << (check1() && check2() && check3() && check4());
	cout << '\n';
	return 0;
}
/*
CSP-J2026游记
# day -inf
考点在朝阳，真是的
# day -1
到酒店了，打了一会板子
# day 1
08:30 开始考试
08:35 开T1
08:55 完成样例并提交
08:55 开T2
08:57 前缀和应该可以
09:03 思路挂了
09:16 无思路
09:17 巧克力好吃
09:18 希望能有个三等，感觉要AFO了，希望上迷惑行为大赏
09:54 已放弃
09:56 开T3
09:57 无思路
10:30 已放弃
10:31 看了T4，无果
10:32 玩了一会code:blocks
10:33 决定打暴力
10:39 T2完成，预计68分
现分数100+68+0+0=168
10:41 重开T3，暴力，预估60分
11:03 完成，预计50分
现分数100+68+50+0=218
11:04 去厕所
11:20 开T4
11:23 思考无果，尝试暴力，预计48
11:39 暴力0分
现分数100+68+50+0=218
11:47 暴力48分
现分数100+68+50+48=266
11:51 发现文件读写没写，改正
*/