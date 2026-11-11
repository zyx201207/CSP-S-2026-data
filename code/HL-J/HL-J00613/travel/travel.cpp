#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
string f(){
    if(c1!=c2) return "0000";
    if(s1.substr(0,2)!=s2.substr(0,2)) return "1000";

    int n1,n2;
    n1=s1[2]-'A'; //012 34
    n2=s2[2]-'A';
    if(!(n1<3 && n2<3 || n1>=3 && n2>=3)) return "1100";
    if(!(abs(n1-n2)==1 && !(n1==2 && n2==3))) return "1110";
    return "1111";
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin>>c1>>s1>>c2>>s2;
    cout<<f();


    return 0;
}
