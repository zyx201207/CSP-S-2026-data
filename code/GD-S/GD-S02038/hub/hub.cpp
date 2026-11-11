#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
signed main(){
	NOTLE::NO_TLE();
	freopen("hub.in","r",stdin),frein=true;
	freopen("hub.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	return 0;
}
