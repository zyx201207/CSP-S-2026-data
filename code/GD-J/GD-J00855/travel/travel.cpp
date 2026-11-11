#include<bits/stdc++.h>
using namespace std;
bool ce(char s1, char s2){
	int a = s1 - 'A', b = s2 - 'A';
	if(0 <= a && a <= 2 && 0 <= b && b <= 2)return true;
	if(3 <= a && a <= 4 && 3 <= b && b <= 4)return true;
	return false;
}
bool li(char s1, char s2){
	int a = s1 - 'A', b = s2 - 'A';
	if(a == 2 && b == 3)return false;
	if(a == 3 && b == 2)return false;
	if(abs(a - b) == 1)return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	int cnt = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		cnt++;
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			cnt++;
			if(ce(s1[2], s2[2])){
				cout << 1;
				cnt++;
				if(li(s1[2], s2[2])){
					cout << 1;
					cnt++;
				}
			}
		}
	}
	for(int i = 1;i <= 4 - cnt;i++)cout << 0;
	return 0;
}
