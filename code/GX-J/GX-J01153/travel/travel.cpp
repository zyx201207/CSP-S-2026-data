#include <bits/stdc++.h>
using namespace std;
char a[4],b=0;
int e,f,g,h;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(nullptr);
    for(int i=0;i<10;i++)cin>>a[i];
    if(a[0]==a[5] && a[1]==a[6]) {
        cout<<1;
        if(a[2]==a[7] && a[3]==a[8]) {
            cout<<1;
            if(a[4]==65 ||a[4]==66 ||a[4]==66){
                if(a[9]==65||a[9]==66||a[9]==67){
                        cout<<1;
                if(a[4]==66 ||a[9]==66)cout<<1;
                else {cout<<0;return 0;}
                }
                else cout<<0<<0;}
            else if(a[9]==68||a[9]==69){cout<<1<<1;return 0;}
            else cout<<0<<0;}
        else cout<<0<<0<<0;
    }else cout<<"0000";
return 0;}
