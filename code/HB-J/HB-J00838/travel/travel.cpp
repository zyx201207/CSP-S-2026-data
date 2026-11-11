#include<bits/stdc++.h>
using namespace std;
bool flag=false;
string tra1,seat1,tra2,seat2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>tra1>>seat1>>tra2>>seat2;
    if(tra1==tra2){
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
    }
    else{
        cout<<"1000";
        return 0;
    }
    if((seat1[2]<='C'&&seat2[2]<='C')||(seat1[2]>'C'&&seat2[2]>'C')){
    }
    else{
        cout<<"1100";
        return 0;
    }
    if((seat1[2]+1)==seat2[2]||(seat1[2]-1)==seat2[2]&&flag){
    }
    else{
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
