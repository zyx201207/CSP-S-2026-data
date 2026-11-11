#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char tp1,tp2;
	cin >> c1 >> s1 >> tp1 >> c2 >> s2 >> tp2;
	if (c1 == c2) 
		cout << 1;
	else cout << 0;
	if (c1 == c2 && s1 == s2) 
		cout << 1;
	else cout << 0;
	if (c1 == c2 && s1 == s2 && ((tp1 >= 'D' && tp2 >= 'D') || (tp1 <= 'C' && tp2 <= 'C'))) 
		cout << 1;
	else cout << 0;
	if (c1 == c2 && s1 == s2 && ((tp1 >= 'D' && tp2 >= 'D') || (tp1 <= 'C' && tp2 <= 'C')) && abs(tp1 - tp2) == 1) 
		cout << 1;
	else cout << 0;
	return 0;
}
