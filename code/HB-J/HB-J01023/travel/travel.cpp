#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[4],c3[3],c4[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    int a=(c1[0]-'0')*10+c1[1]-'0';
    int b=(c3[0]-'0')*10+c3[1]-'0';

    int c=(c2[0]-'0')*10+c2[1]-'0';
    int d=(c4[0]-'0')*10+c4[1]-'0';

    if(a==b) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(c==d) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C'))||((c2[2]>='D'&&c2[2]<='E')&&(c4[2]>='D'&&c4[2]<='E'))){
        cout<<1;
        if(abs(c2[2]-c4[2])==1&&(((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C'))||((c2[2]>='D'&&c2[2]<='E')&&(c4[2]>='D'&&c4[2]<='E')))) cout<<1;
        else cout<<0;
    }
    else cout<<"00";
    return 0;
}
