# include <bits/stdc++.h>
using namespace std;
const int N=1e5+10 ;

int n , a ;
char c ;
string s ;
long long len , ans ;

int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	
	cin >> n ;
	s+=" " ;
	
	for(int i=1 ; i<=n ; i++)
	{
		cin >> a >> c ;
		len+=a ;
		while(a--)
		{
			s+=c ;
		}
	}
	for(int i=1 ; i<=len/2 ; i++)
	{
		if(s[i]!=s[len-i+1])
		{
			ans++ ;
		}
	}
	
	cout << ans ;
	return 0;
}

