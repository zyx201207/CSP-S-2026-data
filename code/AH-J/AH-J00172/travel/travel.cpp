#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int q;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel1.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<1;
        q+=1;
    }else{
        cout<<0;
    }
    if(a1[0]==b1[0]&&a1[1]==b1[1]&&q==1){
        cout<<1;
        q++;
    }else{
        cout<<0;
    }
    if((a1[2]=='D'&&b1[2]=='F')||(a1[2]=='F'&&a1[2]=='D')&&q==2){
        cout<<"11";
    }else if(a1[2]=='D'||a1[2]=='F'&&q==2){
        cout<<"00";
    }else if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='C'&&b1[2]=='B')&&q==2){
        cout<<"11";
    }else{
        cout<<"10";
    }
    return 0;
}
