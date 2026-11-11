#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   string c1,c2;
   char s11,s12,s13,s21,s22,s23;
    cin >> c1>>s11>>s12>>s13>>c2>>s21>>s22>>s23;
    bool flag0 = 0;
    if(c1 == c2){
        cout << 1;
        flag0 = 1;
    }
    else{
        cout <<0;
    }
    bool flag1  =0,flag2 =0;
    if(flag0 == 1&&(s11 == s21&&s12 == s22)){
        cout <<1;
        flag1 = 1;
    }
    else{
        cout << 0;
    }

    if(flag1 == 1&&((s13 - 'A'<3&&s23 - 'A'<3)||(s13 - 'A'>=3&&s13 - 'A'>=3))){
        cout << 1;
        flag2 = 1;}
    else
        cout <<0;
    int a = s13 - 'A', b =s23 - 'A';
    if(flag2 == 1&&((max(a,b) - min(a,b) == 1&&a <3&&b < 3)||(max(a,b) - min(a,b) == 2&&a>=3&&b >= 3)))
        cout <<1;
    else
        cout << 0;
    return 0;
}
