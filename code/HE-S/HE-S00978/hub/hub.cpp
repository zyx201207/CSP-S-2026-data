#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
对于第一组测试数据，共有 10 种合理的建造方案。按通勤半径分类如下：
? 通勤半径为 1 的方案：S = {1,4}，S = {2,4}，S = {2,5}；
? 通勤半径为 2 的方案：S = {1,3}，S = {1,5}，S = {2,3}，S = {3,4}，S = {3,5}；
? 通勤半径为 3 的方案：S = {1,2}，S = {4,5}。
因此，所有合理的建造方案的通勤半径的最小值为 1。
对于第二组测试数据，一种合理的建造方案为 S = {2,7,9}，其中第 2 座城市单独
构成一个连通块，第 7 座和第 9 座城市构成一个连通块。该建造方案的通勤半径为 2。


