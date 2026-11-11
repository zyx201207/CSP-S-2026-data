#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b){
    char aa=max(a[2],b[2]);
    char bb=min(a[2],b[2]);
    if(char(aa-1)==bb)return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;

if(c1==c2){
        cout<<1;
}else{
    cout<<0;
}
if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2)cout<<1;
else cout<<0;
if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))cout<<1;
else cout<<0;
if(s1[1]==s2[1]&&s1[0]==s2[0]&&c1==c2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&check(s1,s2))cout<<1;
else cout<<0;
return 0;
}
