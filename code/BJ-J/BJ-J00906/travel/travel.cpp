#include<bits/stdc++.h>
using namespace std;
string a1,a2,a3,a4;
int e(){
    if(a2[2]-'A'<=2&&a4[2]-'A'<=2)return 1;
    else if(a2[2]-'D'<=1&&a4[2]-'D'<=1&&a2[2]-'D'>=0&&a4[2]-'D'>=0)return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a3>>a4;
    if(a1==a3){
        cout<<1;
        if(a2[1]-'0'+(a2[0]-'0')*10==a4[1]-'0'+(a4[0]-'0')*10){
            cout<<1;
            if(e()==1){
                cout<<1;
                if(a2[2]-a4[2]==-1||a2[2]-a4[2]==1)cout<<1;
                else cout<<0;
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
