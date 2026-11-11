#include<bits/stdc++.h>
using namespace std;
char a1,a2,a3,a4,a5;
char b1,b2,b3,b4,b5;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	cin >> b1 >> b2 >> b3 >> b4 >> b5;
	f = 1;
	if((a1 - '0') * 10 + a2 - '0' != (b1 - '0') * 10 + b2 - '0')f = 0;
	cout << f;
	if((a3 - '0') * 10 + a4 - '0' != (b3 - '0') * 10 + b4 - '0')f = 0;
	cout << f;
	if(!((a5 == 'A' && b5 == 'B')||(a5 == 'A' && b5 == 'C')||(a5 == 'B' && b5 == 'A')||(a5 == 'B' && b5 == 'C')||(a5 == 'C' && b5 == 'A')||(a5 == 'C' && b5 == 'B')||(a5 == 'D' && b5 == 'F')||(a5 == 'F' && b5 == 'D')))f = 0;
	cout << f;
	if(!((a5 == 'A' && b5 == 'B')||(a5 == 'B' && b5 == 'A')||(a5 == 'B' && b5 == 'C')||(a5 == 'C' && b5 == 'B')||(a5 == 'D' && b5 == 'F')||(a5 == 'F' && b5 == 'D')))f = 0;
	cout << f;
	return 0;
}
