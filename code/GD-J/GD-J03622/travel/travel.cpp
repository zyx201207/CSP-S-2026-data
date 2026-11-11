#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

string c1, c2;
string s1, s2;
string x1, x2;
string y1, y2;
bool a, b, c, d;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	x1 = s1[0] + s1[1];
	x2 = s2[0] + s2[1];
	y1 = s1[2];
	y2 = s2[2];
	if(c1 == c2){
		a = true;
		if(x1 == x2){
			b = true;
			if(y1 >= "A" && y1 <= "C"){
				if(y2 >= "A" && y2 <= "C"){
					c = true;
					if(y1 == "A" && y2 == "B")d = true;
					if(y2 == "A" && y1 == "B")d = true;
					if(y1 == "B" && y2 == "C")d = true;
					if(y2 == "B" && y1 == "C")d = true;
					
				}
			}else if(y1 >= "D" && y1 <= "F"){
				if(y2 >= "D" && y2 <= "F"){
					c = true;
					d = true;
				}
			}
		}
		
	}
	cout << a << b << c << d;
	return 0;
}
