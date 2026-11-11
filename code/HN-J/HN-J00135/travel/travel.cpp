#include<bits/stdc++.h>
using namespace std ;
#define ll long long
string c1 , s1 , c2 , s2 ;
map<char , int> mp ; 
void solve()
{
	mp['A'] = 1 ;
	mp['B'] = 2 ;
	mp['C'] = 3 ;
	mp['D'] = 4 ;
	mp['F'] = 5 ;
	cin >> c1 >> s1 >> c2 >> s2 ;
	if(c1 == c2) 
	{
		cout << 1 ;
		if(s1.substr(0 , 2) == s2.substr(0 , 2))
		{
			cout << 1 ;
			if((s1[2] <= 'C') == (s2[2] <= 'C')) 
			{
				cout << 1 ;
				if(abs(mp[s2[2]] - mp[s1[2]]) == 1) cout << 1 ;
				else cout << 0 ;
			}
			else cout << "00" ;
		}
		else cout << "000" ;
	}
	else cout << "0000" ;
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
	freopen("travel.in" , "r" , stdin) ;
	freopen("travel.out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

