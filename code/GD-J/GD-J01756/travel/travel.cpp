#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for (cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
//#define int long long
using namespace std;
string c1,s1,c2,s2,p1,p2;
inline int check(char c) {return 'A'<=c && c<='C';}
start_code
openfile(travel);
cin>>c1>>s1>>c2>>s2;
p1 = s1.substr(0,2),p2 = s2.substr(0,2);
cout
<<(c1==c2)
<<(c1==c2&&p1==p2)
<<(c1==c2&&p1==p2&&check(s1[2])==check(s2[2]))
<<(c1==c2&&p1==p2&&check(s1[2])==check(s2[2])&&abs(s1[2]-s2[2])==1);
stop_code
