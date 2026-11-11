#include<iostream>
#include<cstdio>
using namespace std;
string a1,a2,b1,b2;
int x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    x=int(a2[2]);
    y=int(b2[2]);
    if(a1==b1){
        cout<<1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<1;
            if(((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'))||((b2[2]=='D'||b2[2]=='F')&&(a2[2]=='D'||a2[2]=='F'))){
                cout<<1;
                if(x-y==1||y-x==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
