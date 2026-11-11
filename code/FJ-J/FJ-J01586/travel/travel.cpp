#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
bool ans[5];
void sc()
{
	for(int i = 0; i < 4; i++) cout << ans[i];
	cout << endl;
}
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	
	cin >> c >> s >> c2 >> s2;
	if(c == c2) ans[0] = 1;
	else {ans[0] = 0; ans[1] = 0; ans[2] = 0; ans[3] = 0; sc(); return 0;}
	if(s[0] == s2[0] && s[1] == s2[1]) ans[1] = 1;
	else {ans[1] = 0; ans[2] = 0; ans[3] = 0; sc(); return 0;}
	if((s[2] == 'A' || s[2] == 'B' || s[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) ans[2] = 0;
	else ans[2] = 1;
	if((s[2] == 'D' || s[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) ans[2] = 0;
	else ans[2] = 1;
	if((s[2] == 'A' && s2[2] == 'B') || (s[2] == 'B' && s2[2] == 'C') || (s[2] == 'D' && s2[2] == 'F')) ans[3] = 1;
	else ans[3] = 0;
	if(s[2] == 'C' && s2[2] == 'D') ans[2] = 0;
	sc();
	
	return 0;
}
