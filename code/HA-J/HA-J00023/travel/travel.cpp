#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char _1,_2;
	cin >> c1 >> s1 >> _1 >> c2 >> s2 >> _2;
	cout << (c1==c2);
	cout << ((c1==c2) && (s1==s2));
	cout << ((c1==c2) && (s1==s2) && ((_1<'D' && _2<'D') || (_1>'C' && _2>'C')));
	cout << ((c1==c2) && (s1==s2) && ((_1<'D' && _2<'D') || (_1>'C' && _2>'C')) && ((abs(_1-_2)==1) || ((abs(_1-_2)==2) && ((_1=='F') || (_2=='F')))));
	return 0;
}
