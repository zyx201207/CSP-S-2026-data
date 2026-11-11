#include<bits/stdc++.h>
using namespace std;

int check(string s)
{
	if(s[2] == 'A') return 1;
	if(s[2] == 'B') return 1;
	if(s[2] == 'C') return 1;
	return 0;
}

int add(string s)
{
	if(s[2] == 'A') return 1;
	if(s[2] == 'B') return 2;
	if(s[2] == 'C') return 3;
	if(s[2] == 'D') return 6;
	if(s[2] == 'F') return 7;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin>>s1>>s2>>s3>>s4;
	bool a1 = (s1 == s3); // 车厢号 
	bool a2 = (s2[0] == s4[0] && s2[1] == s4[1]); // 同一排 
	bool a3 = (check(s2) == check(s4)); // 同一侧 
	bool a4(abs(add(s2) - add(s4)) == 1); // 相邻 
	cout<<a1;
	cout<<(a1 && a2);
	cout<<(a1 && a2 && a3);
	cout<<(a1 && a2 && a3 && a4);
	return 0;
}
/*
? 两张车票对应的座位是否在同一节车厢；
? 两张车票对应的座位是否在同一节车厢的同一排；
? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
? 两张车票对应的座位是否相邻。
02 02B 02 01A
1000
*/
