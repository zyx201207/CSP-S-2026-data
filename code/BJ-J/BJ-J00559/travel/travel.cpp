#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2;
    string b1,b2;
    cin>>a1>>a2>>b1>>b2;
    bool f=true;
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        cout<<1;
    }else{
        cout<<0;
        f=false;
    }
    if(a2[0]==b2[0]&&a2[1]==b2[1]&&f==true){
        cout<<1;
    }else{
        cout<<0;
        f=false;
    }
    if(((a2[2]>='A'&&a2[2]<='C')&&(b2[2]>='A'&&b2[2]<='C')&&f==true)||((a2[2]>='D'&&a2[2]<='F')&&(b2[2]>='D'&&b2[2]<='F')&&f==true)){
        cout<<1;
    }else{
        cout<<0;
        f=false;
    }
    if(a2[2]=='D'||b2[2]=='D'){
            if((f==true&&a2[2]=='D'&&b2[2]=='F')||(f==true&&a2[2]=='F'&&b2[2]=='D')){
                cout<<1;
            }else{
                cout<<0;
            }

    }else{
        if((a2[2]-b2[2])<=1&&(a2[2]-b2[2])>=-1&&f==true){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
