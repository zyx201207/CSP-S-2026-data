#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]-'0'==c2[0]-'0'&&c1[1]-'0'==c2[1]-'0'){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag==true){
            cout<<1;
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')&&flag==true){
                cout<<1;
                if(((s1[2]-'0')-(s2[2]-'0')==1)||((s2[2]-'0')-(s1[2]-'0')==1)&&flag==true){
                    cout<<1;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }

    }
    else{
        cout<<"0000";
        return 0;
    }
}
