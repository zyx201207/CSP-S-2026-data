#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[10],b[10],c[10],d[10];
    for(int i=1;i<=2;i++)cin>>a[i];
    for(int i=1;i<=3;i++)cin>>b[i];
    for(int i=1;i<=2;i++)cin>>c[i];
    for(int i=1;i<=3;i++)cin>>d[i];
    int x1=(a[1]-'0');
    x1*=10;
    x1+=(a[2]-'0');
    int x2=(c[1]-'0');
    x2*=10;
    x2+=(c[2]-'0');
    if(x1==x2)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    int y1=b[1]-'0';
    y1*=10;
    y1+=b[2]-'0';
    int y2=d[1]-'0';
    y2*=10;
    y2+=d[2]-'0';
    if(y1==y2)cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    int z1=b[3]-'A'+1,z2=d[3]-'A'+1;
    if(z1==6)z1--;
    if(z2==6)z2--;
    if((z1<=3&&z2<=3)||(z1>=4&&z2>=4))cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if((z1+1)==z2||(z1-1)==z2){
        if((z1<=3&&z2<=3)||(z1>=4&&z2>=4))cout<<"1";
    }
    else cout<<"0";
    return 0;
}
