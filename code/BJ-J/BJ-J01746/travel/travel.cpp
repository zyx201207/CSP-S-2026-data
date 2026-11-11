#include <bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;

int main(){
    cin>>n>>s1>>m>>s2;
    if(n==m)cout<<1;
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    if((s1[3]>='A'&&s1[3]<='C')&&(s2[3]>='A'&&s2[3]<='C')){
        cout<<1;
        if(s1[3]+1==s2[3]||s1[3]-1==s2[3])cout<<1;
    }
    else if((s1[3]>='D'&&s1[3]<='F')&&(s2[3]>='D'&&s2[3]<='F')){
        cout<<1;
        if(s1[3]+2==s2[3]||s1[3]-2==s2[3])cout<<1;
    }
    return 0;
}