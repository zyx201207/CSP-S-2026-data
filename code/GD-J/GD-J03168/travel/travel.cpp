/*
good_luck && have_fun 

虚拟机启动要三分钟，好卡
改个语言设置要注销之后才能生效，手动注销还没反应得等60s自动注销
于是开赛13min之后成功在虚拟机里打开pdf

与此同时我的化竞同学们正在CChO理论考试，祝你们两天全部心态拉满状态好到爆炸稳定发挥全部进集直接飞走
然后全部进入国家队（？）

这个cspj居然只考三个半小时吗我都忘了 

虚拟机同时跑四个对拍卡成啥了，打开个文件夹都要两秒了 
*/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1, s1, c2, s2;
	std::cin >> c1 >> s1 >> c2 >> s2;
	std::string r1 = s1.substr(0, 2), r2 = s2.substr(0, 2);
	char col1 = s1[2], col2 = s2[2];
	if (c1 != c2) {
		std::cout << "0000" << std::endl;
	} else if (r1 != r2) {
		std::cout << "1000" << std::endl;
	} else if ((col1 <= 'C') != (col2 <= 'C')) {
		std::cout << "1100" << std::endl;
	} else if ((col1 <= 'C') && (std::abs(col1 - col2) != 1)) {
		std::cout << "1110" << std::endl;
	} else {
		std::cout << "1111" << std::endl;
	}
	return 0;
}
