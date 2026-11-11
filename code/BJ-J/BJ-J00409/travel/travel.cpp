#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//using ll=long long;

//#define FASTIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int main(){
    //FASTIO;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
            if((a<=3&&b<=3)||(a>=4&&b>=4)){
                cout<<"1";
                if(abs(a-b)==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
