#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int n1 = 10*(s1[0]+'0')+(s1[1]+'0'),n2 = 10*(s2[0]+'0')+(s2[1]+'0');
    char k1 = s1[2],k2 = s2[2];
    bool a = (c1 == c2),b = (a && n1 == n2),c = (b && (k1 <= 'C' && k2 <= 'C') || (k1 >= 'D' && k2 >= 'D')),d = (c && abs(k1-k2) == 1);
    cout<<a<<b<<c<<d;
    return 0;
}