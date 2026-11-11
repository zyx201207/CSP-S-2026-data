#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char a1[3],a2[4],b1[3],b2[4];
bool flag=true,flag2=true;
int main(){
    cin>>a>>b>>c>>d;
    for(int i=1;i<=2;i++){
        a1[i]=a[i-1];
    }
    for(int i=1;i<=3;i++){
        a2[i]=b[i-1];
    }
    for(int i=1;i<=2;i++){
        b1[i]=c[i-1];
    }
    for(int i=1;i<=3;i++){
        b2[i]=d[i-1];
    }
    for(int i=1;i<=2;i++){
        if(a[i]!=c[i]){
            flag=false;
        }
    }
    cout<<int(flag);
    if(flag&&b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(flag&&b[0]==d[0]&&b[1]==d[1]){
        if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
            if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
                cout<<1;
            }
            else{
                cout<<0;
                flag2=false;
            }
        }
        else if(b[2]=='D'||b[2]=='F'){
            if(d[2]=='E'||d[2]=='F'){
                cout<<1;
            }
            else{
                cout<<0;
                flag2=false;
            }
        }
    }
    else{
        cout<<0;
        flag2=false;
    }
    if(flag2&&int(char(b[2]))-int(char(d[2]))==1||int(char(b[2]))-int(char(d[2]))==-1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
