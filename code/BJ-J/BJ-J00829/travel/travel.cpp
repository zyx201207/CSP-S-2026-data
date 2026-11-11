#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int z1=s1[2]-'A',z2=s2[2]-'A';
    string ans="";
    if(c1==c2){
        ans+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+='1';
            if((z1<=2&&z2<=2)||(z1>=3&&z2>=3)){
                ans+='1';
                if(abs(z1-z2)==1||(z1==3&&z2==5)||(z1==5&&z2==3)){
                    ans+='1';
                }else{
                    cout<<"1110";
                    return 0;
                }
            }else{
                cout<<"1100";
                return 0;
            }
        }else{
            cout<<"1000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }

    cout<<ans;

    return 0;
}
