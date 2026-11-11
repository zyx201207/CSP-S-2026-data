#include<bits/stdc++.h>
using namespace std ;
#define ll long long

void solve()
{
	int tot = 0 ;
	while(1)
	{
		system("zao.exe") ;
		system("bao.exe") ;
		system("and.exe") ;
		if(system("fc and.out bao.out"))
		{
			cerr << "Wa" ;
			break ;
		}
		cerr << ++tot << "×éOK\n" ;
	}
}
int main()
{
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
//	freopen(".in" , "r" , stdin) ;
//	freopen(".out" , "w" , stdout) ;
	int oT_To = 1 ;
//	cin >> oT_To ;
	while(oT_To--) solve() ;
	return 0 ;
}

