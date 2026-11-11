#include<bits/stdc++.h>
using namespace std;

#define mj long long
#define mk string

mk a , b , c , d , ss = "ABCDF" , sss , sss1 , ss1 , ss2;
mj s1 , a1 = 1;

int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a >> b >> c >> d;
	if(a != c)a1 = 0;
	else cout << "1";
	sss += b[0];sss += b[1];sss1 += d[0];sss1 += d[1];
	if(sss == sss1 && a1 == 1)cout << "1";
	else  cout << "0";
	if(sss == sss1 && (b[2] == 'A' || b[2] >= 'B' || b[2] >= 'C') && (d[2] == 'A' || d[2] >= 'B' || d[2] >= 'C') || (b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F') && a1 == 1)cout << "1";
	else  cout << "0";
	if(sss == sss1 && ss[b[2] - '0' - 65 + 1]  == ss[d[2] - '0' - 65] && (b[2] == 'A' || b[2] >= 'B' || b[2] >= 'C') && (d[2] == 'A' || d[2] >= 'B' || d[2] >= 'C') || ss[d[2] - '0' - 65 - 1]  == ss[d[2] - '0' - 65] && (b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F') && a1  == 1)cout << "1";
	else cout << "0";
}
