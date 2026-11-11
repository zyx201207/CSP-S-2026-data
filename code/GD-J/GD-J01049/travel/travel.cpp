#include<bits/stdc++.h>
using namespace std;
bool ll(char a, char b){
	if(a == 'D' && b == 'F' || a == 'F' && b == 'D')
		return 1;
	else if(a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C')
		return 1;
	else return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	int n1, n2;
	string s1, s2;
	cin >> n1 >> s1 >> n2 >> s2;
	bool c = 0, p = 0, l = 0;//同车，同排，同侧
	
	//同车
	if(n1 == n2){
		cout << 1;
		c = 1;
	}
	else cout << 0;
	
	
	//同车同排 
	int p1 = (int)s1[0] + s1[1];
	int p2 = (int)s2[0] + s2[1];
	if(c && p1 == p2){
		cout << 1;
		p = 1;
	}
	else cout << 0;
	
	//同车同排同侧 
	if(c && p && ll(s1[2], s2[2])){
		cout << 1;
		l = 1;
	}
	else cout << 0;
	
	//相邻 
	if(c && p && l && int(s1[2]) == int(s2[2]) + 1 || c && p && l && int(s1[2]) == int(s2[2]) - 1){
		cout << 1;
	}
	else cout << 0;
} 
