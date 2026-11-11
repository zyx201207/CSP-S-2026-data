#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,c1,s2,c2;
    cin>>s1>>c1>s2>>c2;
    if(s1%10==s2%10){
        if(s1%100==s2%100){
                cout<<"1";
        }
        else{
        cout<<"0000";
        return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1%100==s2%100){
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i='A'=52;i<='Z';i++){
        if(c1 -5>= c2){
            cout<<"0";
        }
        else{
        cout<<"1";
        }
        if(c1 -26= c2){
        cout<<"1";
        break;
        }
        else{
        cout<<"0";
        break;
        }
    }
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    return 0;
}
