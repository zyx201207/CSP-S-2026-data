#include<bits/stdc++.h>
using namespace std;
char c[5][5],s[5][5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1; i<=2; i++){
        for(int j=1; j<=2; j++)
            cin>>c[i][j];
        for(int j=1; j<=3; j++)
            cin>>s[i][j];
    }
    if(c[1][1]==c[2][1]&&c[1][2]==c[2][2])
        ;
    else{
        cout<<"0000";
        return 0;
    }
    if(s[1][1]==s[2][1]&&s[1][2]==s[2][2])
        ;
    else{
        cout<<"1000";
        return 0;
    }
    if(s[1][3]<='C'){
        if(s[2][3]<='C')
            ;
        else{
            cout<<"1100";
            return 0;
        }
    }else{
        if(s[2][3]>'C')
            ;
        else{
            cout<<"1100";
            return 0;
        }
    }
    if(s[1][3]<s[2][3])
        swap(s[1][3],s[2][3]);
    if(s[1][3]-s[2][3]==1){
        if(s[1][3]=='D'){
            cout<<"1110";
            return 0;
        }
        else
            ;
    }else{
        if(s[1][3]=='F')
            ;
        else{
            cout<<"1110";
            return 0;
        }
    }
    cout<<"1111";
    return 0;
}
