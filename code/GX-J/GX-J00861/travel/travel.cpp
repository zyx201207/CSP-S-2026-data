#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,f1=1,f2=1,f3=1;
    string a1,a2;
    cin>>a>>a1>>b>>a2;
    if(a==b){
        f1=0;
        cout<<1;
    }else{
    cout<<0;
    }
    if(!f1&&a1[0]==a2[0]&&a1[1]==a2[1]){
        cout<<1;
        f2=0;
    }else{
    cout<<0;
    }
    if(!f2&&a1[2]=='A'&&a2[2]=='B'||!f2&&a1[2]=='B'&&a2[2]=='A'||!f2&&a1[2]=='A'&&a2[2]=='C'||!f2&&a1[2]=='C'&&a2[2]=='A'||!f2&&a1[2]=='B'&&a2[2]=='C'||!f2&&a1[2]=='C'&&a2[2]=='B'||!f2&&a1[2]=='D'&&a2[2]=='F'||!f2&&a1[2]=='F'&&a2[2]=='D'){
        f3=0;
        cout<<1;
    }else{
        cout<<0;
    }
    if(!f3&&a1[2]=='A'&&a2[2]=='B'||!f3&&a1[2]=='B'&&a2[2]=='A'||!f3&&a1[2]=='B'&&a2[2]=='C'||!f3&&a1[2]=='C'&&a2[2]=='B'||!f3&&a1[2]=='D'&&a2[2]=='F'||!f3&&a1[2]=='F'&&a2[2]=='D'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
