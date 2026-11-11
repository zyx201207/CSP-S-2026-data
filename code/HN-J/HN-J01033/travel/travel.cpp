#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool cheak(){
	if(s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'A' && s2[2] == 'C' || s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'D' && s2[2] == 'F' )return 1;
	else if(s1[2] == 'B' && s2[2] == 'A' || s1[2] == 'C' && s2[2] == 'A' || s1[2] == 'C' && s2[2] == 'B' || s1[2] == 'F' && s2[2] == 'D')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	cin >>c1 >>s1 >>c2 >>s2;
	if(c1 == c2)cout <<'1';
	else cout <<'0';
	if(s1[0] == s2[0] && s1[1] == s2[0])cout <<'1';
	else cout <<'1';
	if(cheak())cout <<'1';
	else cout <<'0';
	if(abs(int(s1[2] - s2[2])) == 1 && cheak())cout <<'1';
	else cout <<'0'; 
	return 0;
}
