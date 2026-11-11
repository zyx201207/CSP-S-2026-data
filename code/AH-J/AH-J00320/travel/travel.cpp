#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,y1,y2;
    bool f=1;
    cin>>x1>>x2>>y1>>y2;
    if(x2[2]=='F') x2[2]='E';
    if(y2[2]=='F') y2[2]='E';
    if(x1==y1) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if(x2[0]==y2[0]&&x2[1]==y2[1]&&f) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    if((x2[2]<='C'&&y2[2]<='C'||x2[2]>='D'&&y2[2]>='D')&&f) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    int x=x2[2],y=y2[2];
    if((x-y==1||y-x==1)&&f) cout<<1;
    else{
        cout<<0;
        f=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
