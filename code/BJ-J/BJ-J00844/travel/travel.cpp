#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    int h1=(y1[0]-'0')*10+y1[1];
    int h2=(y2[0]-'0')*10+y2[1];
    if(h1==h2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    char c1=y1.back();
    char c2=y2.back();
    if((c1=='A'&&c2=='B')||(c1=='A'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='A')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='A')||(c1=='B'&&c2=='C')||(c1=='C'&&c2=='B')||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
