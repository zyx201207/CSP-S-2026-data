/*
【题目描述】
小R有一个长度为L的字符串S=s1...sL，其中只包含小写英文字母。小R发
现，虽然S可能很长，但它可以分成n个连续的段，其中第i(1≤i≤n)段由ai个小
写英文字母ci 构成。把这n段依次拼接起来便得到S，因此L=∑n i=1 ai。相邻两段中
的字符可以相同。
小X喜欢回文串。若一个字符串反转后与原字符串相同，就称它是回文串，例如
aba、abba 都是回文串，而aabbc不是。也就是说，字符串S 是回文串，当且仅当对
于所有i(1≤i≤L)，均有si=sL+1?i。
小X想让小R把S改成回文串。小R可以将S中任意一个位置的字符修改成任
意小写英文字母。他想用尽量少的修改满足小X的要求。
你需要帮助小R求出，他最少需要修改多少个位置的字符，才能将S改成回文串。
【输入格式】
从文件string.in 中读入数据。
输入的第一行包含一个正整数n。
输入的第i+1(1≤i≤n)行包含一个正整数ai 和一个小写英文字母ci。
【输出格式】
输出到文件string.out 中。
输出一行一个整数，表示小R最少需要修改多少个位置的字符，才能将S改成回
文串。
3
2 a
2 b
1 c
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, p = 0, cnt = 0; cin >> n; vector <char> s;
	int times; char t;
	for (int i = 0; i < n; i++){
		cin >> times; cin >> t;
		for (int j = 0; j < times; j++) s.push_back(t);
		p += times;
	}
	int k = (p % 2) ? (p / 2 + 1) : (p / 2);
	for (int i = 0; i < k; i++){
		if (s[i] != s[p - 1 - i]) cnt++;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
