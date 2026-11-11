#include<bits/stdc++.h>
using namespace std;
char s1,s2,c1,c2;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a=(s1[0]-'0')*10+(s1[1]-'0');
int b=(s2[0]-'0')*10+(s2[1]-'0');

cin>>c1>>s1>>c2>>s2;
if(c1[0]==c1[0]&&c1[1]==c2[1]){ cout<<1;
if(s1[2]==s2[2]) cout<<1;
eles cout<<"0";
if(((s1[2]='F'||s1[2]='D')&&(s2[2]='F'||s2[2]='D'))||((s1[2]='A'||s1[2]='B'||s1[2]='C')&&(s2[2]='A'||s2[2]='B'||s2[2]='C'))){ cout<<1;
    if(s1[2]==s2[2]){
        if(s1[0]==s2[0]&&(a-1==b||a+1==b){
            cout<<1;
        }
    }
    else if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
        if(a==b){
            cout<<1;
        }
    }
    else cout<<0;
}
    else cout<<0;
}
else cout<<"0000";
return 0;
}


