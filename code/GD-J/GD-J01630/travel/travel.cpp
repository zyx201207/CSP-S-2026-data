#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c1,c2;
string s1,s2;
bool samecar,samepai,samesid,lin;

ll chk(char c)
{
	if(c == 'A' || c == 'B' || c == 'C')return 1;
	else return 2;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
		
	if(s1[2] == 'F')s1[2] = 'E';
	if(s2[2] == 'F')s2[2] = 'E';

	samecar = (c1 == c2);
	samepai = (s1[0] == s2[0] && s1[1] == s2[1]);
	samesid = (chk(s1[2]) == chk(s2[2]));
	lin = (abs(s1[2] - s2[2]) == 1);
	
	if(samecar)cout << 1;
	else cout << 0;
	
	if(samecar && samepai)cout << 1;
	else cout << 0;
	
	if(samecar && samepai && samesid)cout << 1;
	else cout << 0;
	
	if(samecar && samepai && samesid && lin)cout << 1;
	else cout << 0;
	
	return 0;
} 
