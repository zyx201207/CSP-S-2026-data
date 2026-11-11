#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1;
	string c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	//questions1
	if (c1 == c2) cout << 1;
	else {
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	
	//questions2
	int tool1 = 0, tool2 = 0;
	for (int i = 0; i<=1; i++){
		tool1 *= 10;
		tool1 += s1[i]-'0';
		
		tool2 *= 10;
		tool2 += s2[i]-'0';	
	}
	if (tool1 == tool2) cout << 1;
	else cout << 0;
	
	//questions3
	if (tool1 == tool2 and ((s1[2] <= 'C' and s2[2] <= 'C') or (s1[2] > 'C' and s2[2] > 'C'))) cout << 1;
	else cout << 0;
	
	//questions4
	int word1 = s1[2]-'A', word2 = s2[2]-'A';
	if (word1 > 2) word1++;
	if (word2 > 2) word2++;
	if (abs(word1 - word2) <= 1){
		if (abs(tool1 - tool2) <= 1) cout << 1;
		else cout << 0;
	}
	else cout << 0;
}
