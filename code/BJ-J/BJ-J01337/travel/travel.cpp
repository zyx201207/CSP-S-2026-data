#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[30];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int id1=s1[2]-'A';
    int id2=s2[2]-'A';
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if((id1<=2&&id2<=2)||(id1>2&&id2>2)){
                cout<<1;
                if(id1+1==id2||id2+1==id1){
                    cout<<1;
                }else{
                    cout<<0;
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
