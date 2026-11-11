#include<bits/stdc++.h>
using namespace std;
//#define int long long //注意longlong内存

//多测清空
//取消fre注释
//检查格式，检查边界
//注意时空复杂度 

//const int N = ;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);//注意不混用cin,scanf,getchar
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2) {
		cout << "0000";
		return 0; 
	}
	cout << 1;
	if(s1[0] != s2[0] || s1[1] != s2[1]) {
		cout << "000";
		return 0;
	}
	cout << 1;
	int n1 = s1[2] - 'A', n2 = s2[2] - 'A';
	if((n1 <= 2 && n2 > 2) || (n1 > 2 && n2 <= 2)) {
		cout << "00";
		return 0;
	}
	cout << 1;
	if(n1 > 2 && abs(n1 - n2) == 2)
		cout << 1;
	else if(n1 <= 2 && abs(n1 - n2) == 1)
		cout << 1;
	else
		cout << 0;
	
	return 0;
	//Trick or Treat!
	//I_AK_IOI
}

