#include<bits/stdc++.h>
using namespace std;
string a,b;
char a1[10],b1[10];
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(a1[0]==b1[0]&&a1[1]==b1[1])cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(a1[2]=='D'||a1[2]=='F'){
        c1=1;
    }
    else{
        c1=0;
    }
    if(b1[2]=='D'||b1[2]=='F'){
        c2=1;
    }
    else{
        c2=0;
    }
    if(c1==c2)cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    int k=a1[2]-b1[2];
    //cout<<endl<<c1<<" "<<k;
    //cout<<endl<<c1<<endl<<c2<<endl<<a1[2]-b1[2]<<endl;
    if(c1==1||k==1||k==-1)cout<<'1';
    //cout<<endl<<c1<<" "<<k;
    else cout<<'0';
    return 0;//02 01C 02 01A
}