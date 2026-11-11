#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int c1, c2;
string s1, s2;
bool flag[5];

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    
    if (c1 == c2) flag[1] = true;
    else flag[1] = false;
    
    int a = (s1[0] - '0') * 10 + (s1[1] - '0');
    int b = (s2[0] - '0') * 10 + (s2[1] - '0');
    
    if (a == b && flag[1]) flag[2] = true;
    else flag[2] = false;
    
    if (s1[2] >= 'A' && s1[2] <= 'C' 
	&& s2[2] >= 'A' && s2[2] <= 'C' && flag[2]
	|| s1[2] >= 'D' && s1[2] <= 'F' 
	&& s2[2] >= 'D' && s2[2] <= 'F' && flag[2]) flag[3] = true;
	else flag[3] = false;
	
	if (s1[2] >= 'A' && s1[2] <= 'C' && s1[2] + 1 == s2[2] && flag[3] 
	|| s1[2] >= 'A' && s1[2] <= 'C' && s1[2] - 1 == s2[2] && flag[3] 
	|| s1[2] >= 'D' && s1[2] <= 'F' && s1[2] - 2 == s2[2] && flag[3] 
	|| s1[2] >= 'D' && s1[2] <= 'F' && s1[2] + 2 == s2[2] && flag[3]) flag[4] = true;
	else flag[4] = false;
	
	for (int i = 1; i <= 4; i++){
		if (flag[i]) cout << 1;
		else cout << 0;
	}
    return 0;
}
