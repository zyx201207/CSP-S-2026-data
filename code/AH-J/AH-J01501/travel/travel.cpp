#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2,t1,t2;
    string b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    if((b1[0]-'0')*10+(b1[1]-'0')!=(b2[0]-'0')*10+(b2[1]-'0')){
        cout<<"1000";
        return 0;
    }
    for(int i=0;i<5;i++)
        if((b1[2]-'A')==i){
            t1=i;
            break;
        }
    for(int i=0;i<5;i++)
        if((b2[2]-'A')==i){
            t2=i;
            break;
        }
    if((t1<=2&&t2>=3)||(t2<=2&&t1>=3)){
        cout<<"1100";
        return 0;
    }
    if(t1-t2==1||t2-t1==1){
        cout<<"1111";
        return 0;
    }
    cout<<"1110";
    return 0;
}
