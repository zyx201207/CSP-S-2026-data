#include<bits/stdc++.h>
using namespace std;
int n,m;
string c0,c1,s1,s0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c0>>c1>>s0>>s1;
    if (c0==s0){
        cout<<"1";
        if (c1[0]==s1[0]&&c1[1]==s1[1]){
            cout<<"1";
            if (c1[2]<='C'&&s1[2]<='C'){
                cout<<"1";
                int a=c1[2],b=s1[2];
                if (abs(a-b)<=1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else if (c1[2]>='D'&&s1[2]>='D'){
                cout<<"1";
                int a=c1[2],b=s1[2];
                if (abs(a-b)<=1){
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
