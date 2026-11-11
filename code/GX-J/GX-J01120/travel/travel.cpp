#include<bits/stdc++.h>
using namespace std;
string s;
string a[10];bool miku[3];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
//
getline(cin,s);
s+=' ';
int s0=0;int a1=0;
for(int i=0;i<s.size();i++){
    if(s[i]==' '){
        for(int i1=s0;i1<i;i1++){
            a[a1]+=s[i1];
        }
        s0=i+1;a1++;
    }
}
//in it
for(int i=0;i<=3;i++){
    miku[i]=0;
}
//begin it
if(a[0]!=a[2]){
    cout<<"0000";
    return 0;
}
else{
    miku[0]=1;
}//1

string s1=a[1],s2=a[3];
if(s1[0]==s2[0]&&s1[1]==s2[1]){
    miku[1]=1;
}
//2

if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')miku[2]=1;
}
else if(s1[2]=='D'||s1[2]=='F'){
    if(s1[2]=='D'||s1[2]=='F')miku[2]=1;
}
//3

if(s1[2]=='A'){
    if(s2[2]=='B')miku[3]=1;
}
else if(s1[2]=='B'){
    if(s2[2]=='A'||s2[2]=='C')miku[3]=1;
}
else if(s1[2]=='C'){
    if(s2[2]=='B')miku[3]=1;
}
else if(s1[2]=='D'){
    if(s2[2]=='F')miku[3]=1;
}
else if(s1[2]=='F'){
    if(s2[2]=='D')miku[3]=1;
}
//4
int cnt=0;
for(;cnt<=3;cnt++){
    if(miku[cnt]==0){
        for(int i=0;i<4-cnt;i++){
            cout<<'0';
        }
        return 0;
    }
    else if(miku[cnt]==1){
        cout<<'1';
    }
}
return 0;
}
