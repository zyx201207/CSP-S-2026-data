#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<1;
        int x,y;
        x=(a2[0]-'0')*10+a2[1]-'0';
        y=(b2[0]-'0')*10+b2[1]-'0';
        if(x==y){
            cout<<1;
            if((b2[2]>'C'&&a2[2]>'C')||(a2[2]<='C'&&b2[2]<='C')){
                cout<<1;
                char a,b;
                a=a2[2],b=b2[2];
                int c1,c2;
                c1=a-'A';
                c2=b-'A';
                if(abs(c1-c2)==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
