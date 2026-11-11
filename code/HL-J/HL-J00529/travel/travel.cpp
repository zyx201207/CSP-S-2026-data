#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a1[10],a2[10],b1[10],b2[10];
    cin>>a1>>a2>>b1>>b2;
    int a=a1[1],b=b1[1];
    if(a==b)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    int x=a2[0]*10+a2[1],x1=b2[0]*10+b2[1];
    if(x==x1) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    x=a2[2]-64,x1=b2[2]-64;
    if(x==6) x=5;
    if(x1==6) x1=5;
    if(x<=3 && x1<=3) cout<<1;
    else if(x>=4&&x1>=4) cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if((x==3 && x1==4)||(x==4 && x1==3)) cout<<0;
    else if(x1==x+1 || x1==x-1) cout<<1;
    else cout<<0;
    return 0;
}
