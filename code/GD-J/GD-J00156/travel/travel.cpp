#include <bits/stdc++.h>
using namespace std ;
namespace LIXUEAN{
	typedef long long ll ;
	typedef pair<ll,ll> Pir ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	#define fir         first
	#define sec         second
	//1000 ms 1024M
	string c1,s1,c2,s2,tmp = "0ABCDF" ;
	void Main(){
		cin >> c1 >> s1 >> c2 >> s2 ;
		if(c1 != c2){ cout << "0000" ; return ; }
		cout << 1 ;
		if(s1[0] != s2[0] || s1[1] != s2[1])
			{ cout << "000" ; return ; }
		cout << 1 ;
		ll id1 = tmp.find(s1[2]),id2 = tmp.find(s2[2]) ;
		if(bool(id1 <= 3) != bool(id2 <= 3))
			{ cout << "00" ; return ; }
		cout << 1 ;
		if(abs(id1 - id2) != 1)
			{ cout << "0" ; return ; }
		cout << 1 ;
		return ;
	}
} ;
int main(){
	//写快读的话记得关掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
