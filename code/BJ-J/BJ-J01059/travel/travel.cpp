#include <bits/stdc++.h>
using namespace std;
const int N=2e6+6;
#define int long long


signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.txt","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    cout<<((c1==c2)?1:0);
    cout<<((c1==c2 && s1[0]==s2[0] && s1[1]==s2[1])?1:0);
    cout<<((c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')))?1:0);
    cout<<((c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')) && (s1[2]-s2[2]==1 || s1[2]-s2[2]==-1))?1:0);
}