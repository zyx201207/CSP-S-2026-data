#include<bits/stdc++.h>
using namespace std;
#define rep(_1, _2, _3) for(int _1=(_2), __##_1##__=(_3); _1<=__##_1##__; ++_1)
typedef long long LL;  typedef unsigned long long ULL;  typedef long double LD; 
const int inf=0x7F7F7F7F, inf2=0x3F3F3F3F; 
const int N=0, M=0, K=0; 
string c1, s1, c2, s2;
int C, S, X, C2, S2, X2;
char table[7][8]={"", " 212   ", " 121   ", " 212   ", "    2 1", "", "    1 2"}; // '1'=near, '2'=not near but in the same side

void initialize() {}

bool __main() {
    cin>>c1>>s1>>c2>>s2;
    C=(c1[0]^48)*10+(c1[1]^48), S=(s1[0]^48)*10+(s1[1]^48), X=s1[2]^64;
    C2=(c2[0]^48)*10+(c2[1]^48), S2=(s2[0]^48)*10+(s2[1]^48), X2=s2[2]^64;
    if(C!=C2) cout<<"0000\n";
    else if(S!=S2) cout<<"1000\n";
    else if(table[X][X2]==' ') cout<<"1100\n";
    else if(table[X][X2]!='1') cout<<"1110\n";
    else cout<<"1111\n";
    return 0;
}
int main() {
    freopen("travel.in", "r", stdin), freopen("travel.out", "w", stdout); // PAY ATTENTION!! 
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);  initialize(); 
    int _=1; /* cin>>_; */ for(;_>0;--_) if(__main()) return 0; 
    return 0; 
}