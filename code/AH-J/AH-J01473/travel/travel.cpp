#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s="";
void check() {
    if(c1==c2) {
        s+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]) {
            s+='1';
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') {
                s+='1';
                if(abs(s1[2]-s2[2])==1) {
                    s+='1';
                }
            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') {
                s+='1';
                if(abs(s1[2]-s2[2])==1) {
                    s+='1';
                }
            }
        }
    }
    return;
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    check();
    cout<<s;
    if(s.size()<4) {
        for(int i=4;i>s.size();i--) cout<<'0';
    }
    return 0;
}
