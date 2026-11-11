#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long q1,q2,p1,p2;
    char a,b;
    cin>>q1>>p1>>a>>q2>>p2>>b;
    bool l1=0,l2=0,l3=0;
    if(q1==q2){
        cout<<1;
        l1=1;
    }else{
        cout<<0;
    }
    if(p1==p2&&l1==1){
        cout<<1;
        l2=1;
    }else{
        cout<<0;
    }
    if(a=='A'&&b=='B'&&l1==1&&l2==1||a=='A'&&b=='C'&&l1==1&&l2==1||a=='B'&&b=='A'&&l1==1&&l2==1||a=='B'&&b=='C'&&l1==1&&l2==1||a=='C'&&b=='A'&&l1==1&&l2==1||a=='C'&&b=='B'&&l1==1&&l2==1||a=='D'&&b=='F'&&l1==1&&l2==1||a=='F'&&b=='D'&&l1==1&&l2==1){
        cout<<1;
        l3=1;
    }else{
        cout<<0;
    }
    if(a=='A'&&b=='B'&&l1==1&&l2==1&&l3==1||a=='B'&&b=='A'&&l1==1&&l2==1&&l3==1||a=='B'&&b=='C'&&l1==1&&l2==1&&l3==1||a=='C'&&b=='B'&&l1==1&&l2==1&&l3==1||a=='D'&&b=='F'&&l1==1&&l2==1&&l3==1||a=='F'&&b=='D'&&l1==1&&l2==1&&l3==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
