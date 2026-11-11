#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool okc,okp,okce,okxl;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >>c2 >>s2;
    if(c1 == c2){
        okc = 1;
        string p1,p2;
        p1 = s1[0]+s1[1];
        p2 = s2[0]+s2[1];
        if(p1 == p2 && okc){
            okp = 1;
            if((s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') && okp && okc){
                okce = 1;
                if((s1[2] == s2[2]+1 || s1[2] == s2[2]-1) && okce && okp && okc){
                    okxl = 1;
                }
            }
        }
    }
    cout <<okc <<okp <<okce <<okxl;
    return 0;
}
