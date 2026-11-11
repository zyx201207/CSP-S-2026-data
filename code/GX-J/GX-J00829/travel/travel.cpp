#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",std-in);
    freopen("travel.out","w",std-out);
    int c,s;
    string c1,s1;
    cin>>c>>s>>c1>>s1;
    if(c==s){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1[0]==s1[0]&&c1[1]==s1[1]&&c==s){
        cout<<1;
        }
    else{
        cout<<0;
        }
    if(c1[0]==s1[0]&&c1[1]==s1[1]&&(c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&c==s){
        cout<<1;
        }
    else{
        cout<<0;
        }
    if(c==s&&c1[0]==s1[0]&&c1[1]==s1[1]&&c==s&&c1[0]==s1[0]&&c1[1]==s1[1]&&(c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(s1[2]=='A'||s1[2]=='C')&&c==s&&((c1[2]=='A'&&s1[2]=='B')||c1[2]=='B'&&s1[2]=='A'||c1[2]=='B'&&s1[2]=='C'||c1[2]=='C'&&s1[2]=='B'||c1[2]=='D'&&s1[2]=='F'||c1[2]=='F'&&s1[2]=='D'){
        cout<<1;
        }
    else{
        cout<<0;
        }
    return 0;
}
