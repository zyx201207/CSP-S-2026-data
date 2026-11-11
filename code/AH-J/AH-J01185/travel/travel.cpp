#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char a[3],b[4],c[3],d[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool x=1,y=1,m=1,n=1;
    for(int i=0;i<2;i++)cin>>a[i];
    for(int i=0;i<3;i++)cin>>b[i];
    for(int i=0;i<2;i++)cin>>c[i];
    for(int i=0;i<3;i++)cin>>d[i];
    for(int i=0;i<2;i++){
        if(a[i]!=c[i])x=0;
        if(b[i]!=d[i])y=0;
    }
    if(x==0)y=0;
    if(b[2]>='A'&&d[2]<='C'&&x==1&&y==1||b[2]>='D'&&d[2]<='F'&&x==1&&y==1)m=1;
    else m=0;
    if(m==1&&b[2]+1==d[2]||m==1&&b[2]-1==d[2])n=1;
    else n=0;
    cout<<x<<y<<m<<n;
        return 0;
}
