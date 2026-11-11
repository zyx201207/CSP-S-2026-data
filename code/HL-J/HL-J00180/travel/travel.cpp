#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    char c1[2],s1[3],c2[2],s2[3];
    int flag=0,imp=0;
    for(int i=0;i<2;i++){
         cin>>c1[i];
    }
    for(int i=0;i<3;i++){
         cin>>s1[i];
    }
    for(int i=0;i<2;i++){
         cin>>c2[i];
    }
    for(int i=0;i<3;i++){
         cin>>s2[i];
    }
    if(c1[0]==c2[0]&&c1[1]==c2[1]) cout<<"1";
    else cout<<"0";
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
        flag=1;
    }
    else cout<<"0";
    if(flag==1&&s1[2]<='C'&&s2[2]<='C'){
        cout<<"1";
        imp=1;
    }
    else if(flag==1&&s1[2]>='D'&&s2[2]>='D'){
        cout<<"1";
        imp=1;
    }
    else cout<<"0";
    if(imp==1&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]+1==s2[2]){
        if(s2[2]=='C'&&s1[2]=='D')cout<<"0";
        else if(s1[2]=='C'&&s1[2]=='D')cout<<"0";
        else cout<<"1";
    }
    else if(imp==1&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]-1==s2[2]){
        if(s2[2]=='C'&&s1[2]=='D')cout<<"0";
        else if(s1[2]=='C'&&s1[2]=='D')cout<<"0";
        else cout<<"1";
    }
    else cout<<"0";
return 0;
}
