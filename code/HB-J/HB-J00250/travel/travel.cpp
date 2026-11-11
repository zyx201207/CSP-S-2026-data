#include <bits/stdc++.h>
using namespace std;
string sa1,sa2,sb1,sb2;
int a[10],b[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>sa1>>sa2>>sb1>>sb2;
    a[0]=1,a[1]=1,a[2]=1,a[3]=2,a[4]=2;
    b[0]=0,b[1]=1,b[2]=2,b[3]=3,b[4]=4;
    if(sa1!=sb1){
        cout<<"0000\n";
    }
    else{
        cout<<"1";
        if(sa2[0]==sb2[0]&&sa2[1]==sb2[1]){
            cout<<"1";
            if(a[sa2[2]-'A']==a[sb2[2]-'A']){
                cout<<"1";
                if(abs(b[sa2[2]-'A']-b[sb2[2]-'A'])==1){
                    cout<<"1\n";
                }
                else{
                    cout<<"0\n";
                }
            }
            else{
                cout<<"00\n";
            }
        }
        else{
            cout<<"000";
        }
    }
    return 0;
}
