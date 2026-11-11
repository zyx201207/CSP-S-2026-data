#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_first,s_first,c_second,s_second;

    cin >> c_first >> s_first >> c_second >> s_second;

    if (c_first == c_second){
        cout << 1;
    }
    else{
        cout << 0;
    }

    int same_s=0;
    int over_l = abs((s_first[2]-'0')-(s_second[2]-'0'));
    int f_cd = s_first[2]-'0';
    int s_cd = s_second[2]-'0';
    int passage=0;
    int pass_away=0;

    for (int i=0;i<2;i++){
        if(s_first[i]==s_second[i]){
            same_s++;
        }
    }

    if (f_cd==19){
        if (s_cd==20){
            passage = 1;
        }
    }
    else if (f_cd==20){
        if (s_cd==19){
            passage = 1;
        }
    }

    if (same_s==2){
        cout << 1;
        if (over_l <=2 && passage==0){
        cout << 1;
        }
        else{
            pass_away=1;
        }
    }
    else{
        cout << 0;
    }

    if (pass_away==1){
        cout << 0;
    }
    if (over_l <=1 && passage==0){
        cout << 1;
    }
    else {cout << 0;}

    return 0;
}
