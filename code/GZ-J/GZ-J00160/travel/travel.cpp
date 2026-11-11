//GZ-J00160 贵阳市第三中学 严介谦
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int a1=a[0]*10+a[1],b1=b[0]*10+b[1],c1=c[0]*10+c[1],d1=d[0]*10+d[1];
    if(a1!=c1){
        cout<<0<<0<<0<<0;
        return 0;
    }cout<<1;
    char b2=b[2],d2=d[2];
    if(b1!=d1){
        cout<<0<<0<<0;
        return 0;
    }cout<<1;
    if(b2<='C'&&d2>'C'||b2>'C'&&d2<='C'){
        cout<<0<<0;
        return 0;
    }cout<<1;
    if(!(b2==d2+1||d2==b2+1||b2=='D'&&d2=='F'||b2=='F'&&d2=='D')){
        cout<<0;
        return 0;
    }cout<<1;
    return 0;
}
