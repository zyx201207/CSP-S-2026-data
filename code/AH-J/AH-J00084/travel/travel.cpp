#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_1,c_2,s_1,s_2;
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1!=c_2){
        cout<<"0000\n";
        return 0;
    }
    else if(c_1==c_2){
        cout<<"1";
        if(s_1[0]==s_2[0]&&s_1[1]==s_2[1]){
            cout<<"1";
        }else{
            cout<<"000\n";
            return 0;
        }
        if(s_1[2]>='D'&&s_1[2]<='E'&&s_2[2]>='D'&&s_2[2]<='E'){
            cout<<"11\n";
            return 0;
        }else{
            if(((s_2[2]>='D'&&s_2[2]<='E')&&(s_1[2]>='A'&&s_1[2]<='C'))||((s_1[2]>='D'&&s_1[2]<='E')&&(s_2[2]>='A'&&s_2[2]<='C'))){
                cout<<"00\n";
                return 0;
            }
            else if(((s_1[2]=='A'&&s_2[2]=='B')||(s_1[2]=='B'&&s_2[2]=='C'))||((s_2[2]=='A'&&s_1[2]=='B')||(s_2[2]=='B'&&s_1[2]=='C'))){
                cout<<"11\n";
                return 0;
            }
            else{
                cout<<"10\n";
                return 0;
            }
        }
    }
    return 0;
}
