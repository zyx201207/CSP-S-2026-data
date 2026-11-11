#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	freopen("D://GD-S00908//subway/subway.out","r",stdin);
	char c;
	while ((c=getchar())!=EOF) s1.push_back(c);
//	s1.pop_back();
	freopen("D://csps-new//down//subway//subway7.ans","r",stdin);
	while ((c=getchar())!=EOF) s2.push_back(c);
	if (s1==s2) cout <<"AC!";
	else cout <<"WA!";
	return 0;
}
