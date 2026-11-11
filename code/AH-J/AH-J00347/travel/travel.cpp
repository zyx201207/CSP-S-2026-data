#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
        if(c1[0]==c2[0]&&c1[1]==c2[1]){
            cout<<"1";
            if(int(c1[2])<=int('C')&&int(c2[2])<=int('C')||int(c1[2])>int('C')&&int(c2[2])>int('C')){
                cout<<"1";
                if(int(c1[2])-int(c2[2])==1||int(c2[2])-int(c1[2])==1) cout<<"1";
                else cout<<"0";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
