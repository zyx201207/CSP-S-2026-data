#include<iostream>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	int c1=-1, c2=-2;
	string s1, s2, sum="0000";
	cin >> c1 >> s1 >> c2 >> s2;
	int m1=max(s1[2], s2[2]), m2=min(s1[2],s2[2]);
	if(c1 == c2 && c1 != 1 && c1 != 16) {
	sum[0]='1';
	if(s1[0] == s2[0] && s1[1]==s2[1]) {
		sum[1]='1';
		if((s1[2] <= 'C' && s2[2] <= 'C' )||(s1[2] >= 'D' && s2[2] >= 'D')) sum[2]='1';
			if(m1-m2 == 1 && m1 != 'D') sum[3]='1';
	}
}
	
	cout << sum;
	fclose(stdin);
	fclose(stdout);
} 
