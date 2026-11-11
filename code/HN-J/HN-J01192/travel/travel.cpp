#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int a1, b1;
	string a2, b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1) cout<<"0000\n";
	else if(a2.substr(0, 2)!=b2.substr(0, 2)) cout<<"1000";
	else if(!(a2[2]>='D' && b2[2]>='D' || a2[2]<'D' && b2[2]<'D')) cout<<"1100";
	else if(a2[2]<'D' && b2[2]<'D' && abs(a2[2]-b2[2])==1) cout<<"1111";
	else if(a2[2]>='D' && b2[2]>='D') cout<<"1111";
	else cout<<"1110";
	return 0;
}
/*
         J       U          U      N          N                      CCCCC                   A               TTTTTTTTTTTT
         J       U          U      NN         N                     C     C                 A A                   T
         J       U          U      N N        N                    C       C               A   A                  T
         J       U          U      N  N       N                   C         C             A     A                 T
         J       U          U      N    N     N                  C                       A       A                T
         J       U          U      N     N    N                  C                      AAAAAAAAAAA               T 
         J       U          U      N      N   N                   C                    A           A              T
    J    J       U          U      N       N  N                   C         C         A             A             T
    J    J        U        U       N        N N                    C       C         A               A            T
     J  J          U      U        N         NN                     C     C         A                 A           T
      JJ            UUUUUU         N          N                      CCCCC         A                   A          T
*/ 
