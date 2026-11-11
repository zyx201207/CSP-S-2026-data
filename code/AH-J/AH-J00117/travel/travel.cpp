#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a,b,c,d;
    cin >> c1;
    for(int i=1;i<=3;i++){
        cin >> s1[i];
    }
    cin >> c2;
    for(int i=1;i<=3;i++){
        cin >> s2[i];
    }
    if(c1==c2){
        a=1;
        if((s1[1]==s2[1])&&(s1[2]==s2[2])){
            b=1;
            if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
                c=1;
                if((abs((s1[3]-'0')-(s2[3]-'0'))==1)&&(s1[3]!='C'||s1[3]!='D')&&(s2[3]!='D'||s2[3]!='C')){
                    d=1;
                }else{
                    cout << "1110";
                    return 0;
                }
            }else{
                cout << "1100";
                return 0;
            }
        }else{
            cout << "1000";
            return 0;
        }
    }else{
        cout << "0000";
        return 0;
    }
    cout << "1111";
    return 0;
}
