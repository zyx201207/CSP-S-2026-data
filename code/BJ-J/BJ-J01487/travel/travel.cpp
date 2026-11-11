#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    char x=b1[b1.size()-1],y=b2[b2.size()-1];
    if(a1==a2){
        cout<<"1";
        string p1=b1.substr(0,2),p2=b2.substr(0,2);
        if(p1==p2){
            cout<<"1";
            if((x<='C' && y<='C') || (x>='D' && y>='D')){
                cout<<"1";
                if((x-y==1 && x!='D') || (y-x==1 && y!='D')){
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
    putchar('\n');
    return 0;
}