#include <iostream>
using namespace std;
string s1,s2,s3,s4;
int f1,f2,f3,f4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3) f1 = 1;
	if(s2[0] == s4[0] && s2[1] == s4[1] && f1) f2 = 1;
	char a = s2[2],b = s4[2];
	if(f2 && ((a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C') || (a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F'))) f3 = 1;
	if(a > b) swap(a,b);
	if(f3 && b - a == 1 && a != 'C') f4 = 1;
	cout << f1 << f2 << f3 << f4 << endl;
	return 0;
}
