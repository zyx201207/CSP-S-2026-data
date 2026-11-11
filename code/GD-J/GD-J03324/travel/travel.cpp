//感觉J组一点也不难（？）
#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char s1a,s1b,s1c,s2a,s2b,s2c;
bool a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c1 >> s1a >> s1b >> s1c;
	cin >> c2 >> s2a >> s2b >> s2c;
	a1 = a2 = a3 = a4 = 0;
	if (c1 == c2){
		a1 = 1;
		if (s1a == s2a && s1b == s2b){
			a2 = 1;
			if ((s1c>='D' && s2c>='D') || (s1c<'D' && s2c<'D')){
				a3 = 1;
				if (abs(s1c-s2c) == 1 || (s1c == 'D'&&s2c == 'F') || (s1c == 'F'&&s2c == 'D')){
					a4 = 1;
				}
			}
		}
	}
	cout << a1 << a2 << a3 << a4;
}
