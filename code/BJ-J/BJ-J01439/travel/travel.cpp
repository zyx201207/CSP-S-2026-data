#include<bits/stdc++.h>
using namespace std;

char a[100];
char b[100];

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    for(int i=1;i<=5;i++){
        cin>>a[i];
    }
    for(int i=1;i<=5;i++){
        cin>>b[i];
    }

    if(a[1]==b[1] && a[2]==b[2]){
        if(a[3]==b[3] && a[4]==b[4]){
            if(a[5]==b[5]+1 || a[5]==b[5]-1){
                if((a[5]=='C' || a[5]=='D') && (b[5]=='C' || b[5]=='D')) cout<<"1100";
                else cout<<"1111";
            }
            else cout<<"1110";
        }
        else cout<<"1000";
    }

    else cout<<"0000";

    return 0;

}