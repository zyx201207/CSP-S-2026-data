#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int A,B,C,D,F;
    if(c1==c2) cout<<1;
    else cout<<0;

    if(s1<=s2) cout<<1;
    else cout<<0;

    if(s1>=s2) cout<<1;
    else cout<<0;

    if((A==A)||(B==B)||(C==C)||(D==D)||(F==F)) cout<<1;
    else cout<<0;
    return 0;
}
