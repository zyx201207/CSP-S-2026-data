#include<bits/stdc++.h>
using namespace std;
int a,b,x[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool z=1;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b) x[1]=1;
    if(c[0]==d[0]&&c[1]==d[1]) x[2]=1;
    if((c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C')||(c[2]>='D'&&c[2]<='F'&&d[2]>='D'&&d[2]<='F')) x[3]=1;
    if(c[2]+1==d[2]) x[4]=1;
    for(int i=1;i<=4;i++){
        if(x[i]==0) z=0;
        cout<<z;
    }
    return 0;
}
