#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a1=0,a2=0;
    cin >>c1 >> s1 >> c2 >>s2;
    if(c1==c2){
        if(s1[0]==s2[0] && s1[1]==s2[1]){
           char a=s1[2],b=s2[2];
            if (a>='A'&& a<='C') a1=1;
            if (b>='A'&& b<='C') a2=1;
            if(a1==1&&a2==1) {
                if(a==b+1||a==b-1) cout <<"1111";
                else cout << "1110";
                }
                else if(a1==0&&a2==0) {
                if(a==b+1||a==b-1) cout <<"1111";
                else cout << "1110";
                }
            else cout << "1100";
        }
        else cout << "1000";
    }else cout << "0000";

    return 0;
}
