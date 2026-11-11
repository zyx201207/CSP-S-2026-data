#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[1001];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    int p1=10*int(a[0]-'0')+int(a[1]-'0');
    int p2=10*int(a[5]-'0')+int(a[6]-'0');
    if(p1==p2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    p1=10*int(a[2]-'0')+int(a[3]-'0');
    p2=10*int(a[7]-'0')+int(a[8]-'0');
    if(p1==p2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    p1=int(a[4]-'A')+1;
    p2=int(a[9]-'A')+1;
    if(0<=p1<=3&&0<=p2<=3){
        cout<<1;
    }else if(4<=p1<=5&&4<=p2<=5){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(p1==0&&p2==1||p1==1&&p2==0||p1==2&&p2==3||p1==3&&p2==2||p1==4&&p2==5||p1==5&&p2==4){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
