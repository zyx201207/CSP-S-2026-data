#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2,seat1,seat2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    x1=(s1[0]-'0')*10+(s1[1]-'0');
    x2=(s2[0]-'0')*10+(s2[1]-'0');
    seat1=s1[2]-'A'+1;
    seat2=s2[2]-'A'+1;
    if(c1==c2){
        cout<<1;
        if(x1==x2){
            cout<<1;
            if(seat1<=3&&seat2<=3){
                cout<<1;
                if(seat1==1&&seat2==2) cout<<1;
                else if(seat1==2) cout<<1;
                else if(seat1==3&&seat2==2) cout<<1;
                else cout<<0;
            }else if(seat1>3&&seat2>3){
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
