#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n1,n2;
    bool flag1=true,flag2=true;
    int a1[5],b1[5];
    string a,b;
    cin>>n1>>a>>n2>>b;
    if(n1==n2){
        cout<<"1";
    }else{
        cout<<"0";
        flag1=false;
    }
    if(a[0]==b[0]&&a[1]==b[1]&&flag1==true){
        cout<<"1";
    }else{
        cout<<"0";
        flag2=false;
    }
    if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='D'||b[2]=='F')||flag1==false||flag2==false){
        cout<<"0";
    }else{
        cout<<"1";
    }
    if((a[2]==b[2]+1||a[2]==b[2]-1)&&flag1==true&&flag2==true){
        if((a[2]=='C'&&b[2]=='D')||(a[2]=='D'&&b[2]=='C')){
            cout<<"0";
            return 0;
        }
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
