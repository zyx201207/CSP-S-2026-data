
#include<bits/stdc++.h>
using namespace std;
int a1,b1,s1,s2,x1,x2;
string a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    cin>>a1>>a2>>b1>>b2;
    //cout<<a1;
    if(a1==b1){
        cout<<"1";
        s1=10*(a2[0]-'0')+(a2[1]-'0');
        s2=10*(b2[0]-'0')+(b2[1]-'0');
        if(s1==s2){
            cout<<"1";
            x1=a2[2]-'A'+1;
            x2=b2[2]-'A'+1;
            if((1<=x1&&x1<=3)&&(1<=x2&&x2<=3))
            {
                cout<<"1";
                if(max(x1,x2)-min(x1,x2)==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else if((4<=x1&&x1<=6)&&(4<=x2&&x2<=6))
            {
                cout<<"11";

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
