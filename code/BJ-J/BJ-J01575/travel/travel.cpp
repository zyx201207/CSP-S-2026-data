#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        if(s1[1] == s2[1] && s1[0] == s2[0]){
            if((s1[2] >= 'A' && s1[2] <= 'C'&&s2[2] >= 'A' && s2[2] <= 'C')||(s1[2] >= 'D' && s1[2] <= 'E'&&s2[2] >= 'D' && s2[2] <= 'E')){
                if((s1[2] == 'A' && s2[2] == 'B')||(s1[2] == 'B' && s2[2] == 'A')||(s1[2] == 'B' && s2[2] == 'C')||(s1[2] == 'C' && s2[2] == 'B')||(s1[2] == 'D' && s2[2] == 'E')||(s1[2] == 'E' && s2[2] == 'D')){
                    cout << "1111";
                }
                else cout << "1110";
            }
            else cout << "1100";
        }
        else cout << "1000";
    }
    else cout << "0000";

    return 0;
}
/*呃啊，打完这次就想退了，希望上一次迷惑行为大赏*/
/*
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
*/
