#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool p=false,p2=false,p3=false;
int jue(int a,int b) {
    if(a>=b) return a-b;
    else return b-a;
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
        cout<<1;
        p=true;
    }
    else cout<<0;
    if(p&&s1[0]==s2[0]&&s1[1]==s2[1]) {
        cout<<1;
        p2=true;
    } else cout<<0;
    if(p&&p2&&((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))) {
        cout<<1;
        p3=true;
    } else cout<<0;
    if(p&&p2&&p3&&(jue((int)s1[2],(int)s2[2])==1)) {
        cout<<1;
    } else cout<<0;
    return 0;
}