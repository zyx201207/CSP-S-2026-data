#include <iostream>
#include <string>
using namespace std;

int c1, c2;
string s1, s2;

int fun1(char x, char y){
	int cnt = 0;
	if (x == 'A' || y == 'A')
		cnt++;
	if (x == 'B' || y == 'B')
		cnt++;
	if (x == 'C' || y == 'C')
		cnt++; 
	return cnt;
}

int fun2 (char x, char y){
	int cnt = 0;
	if (x == 'D' || y == 'D')
		cnt++;
	if (x == 'E' || y == 'E')
		cnt++;
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 =#include <iostream>
#include <string>
using namespace std;

int c1, c2;
string s1, s2;

int fun1(char x, char y){
	int cnt = 0;
	if (x == 'A' || y == 'A')
		cnt++;
	if (x == 'B' || y == 'B')
		cnt++;
	if (x == 'C' || y == 'C')
		cnt++; 
	return cnt;
}

int fun2 (int x, int y){
	int cnt = 0;
	if (x == 'D' || y == 'D')
		cnt++;
	if (x == 'E' || y == 'E')
		cnt++;
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//freopen("travel.in", "r", stdin);
	//freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2){ // 在同一节车厢
		cout << 1;
		string pai1 = "";
		string pai2 = "";
		for(int i=0; i<2; i++){
			pai1 += s1[i];
			pai2 += s2[i];
		}
		
		if (pai1 == pai2){ // 在同一节车厢的同一排
			cout << 1;
			char zuo1 = s1[2];
			char zuo2 = s2[2];
			int f1 = fun1(zuo1, zuo2);
			int f2 = fun2(zuo1, zuo2);
			if (f1 == 2 || f2 == 2){
				// 在同一节车厢的同一排，且位于过道的同一侧
				cout << 1;
				if (f2 == 2){ // 一定相邻 
					cout << 1;
				}
				else{
					if (zuo1 == 'B' || zuo2 == 'B')
						// 相邻
						cout << 1;
					else 
						cout << 0; 
				}
			}
			else  // 在同一排，不在同一侧 
				cout << 0 << 0;
		}
		else // 都不在同一排 
			cout << 0 << 0 << 0;
	}	
	else
		cout << 0 << 0 << 0 << 0;
	
	return 0;
}= c2){ // 在同一节车厢
		cout << 1;
		string pai1 = "";
		string pai2 = "";
		for(int i=0; i<2; i++){
			pai1 += s1[i];
			pai2 += s2[i];
		}
		
		if (pai1 == pai2){ // 在同一节车厢的同一排
			cout << 1;
			char zuo1 = s1[2];
			char zuo2 = s2[2];
			int f1 = fun1(zuo1, zuo2);
			int f2 = fun2(zuo1, zuo2);
			if (f1 == 2 && f2 == 2){
				// 在同一节车厢的同一排，且位于过道的同一侧
				cout << 1;
				if (f2 == 2){ // 一定相邻 
					cout << 1;
				}
				else{
					if (zuo1 == 'B' || zuo2 == 'B')
						// 相邻
						cout << 1;
					else // 不相邻 
						cout << 0; 
				}
			}
			else  // 在同一排，不在同一侧 
				cout << 0 << 0;
		}
		else // 都不在同一排 
			cout << 0 << 0 << 0;
	}	
	else
		cout << 0 << 0 << 0 << 0;
	
	return 0;
}
