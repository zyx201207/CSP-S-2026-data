#include <bits/stdc++.h>
using namespace std;
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	string a,b,c,d;
	cin >> a>>b>>c>>d;
	if(a!=c)cout << "0000";
	else if(b[0]!=d[0]||b[1]!=d[1])cout <<"1000";
	else if(!(('A'<=b[2]<='C'&&'A'<=d[2]<='C')||('D'<=b[2]<='F'&&'D'<=d[2]<='F')))cout << "1100";
	else if(b[2]+1==d[2]||d[2]+1==b[2])cout <<"1111";
	else cout <<"1110";
	return 0;
}
