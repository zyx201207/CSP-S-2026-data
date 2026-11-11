#include<bits/stdc++.h>
using namespace std;
int a,b;
char s1[3],s2[3];
bool f1=0,f2=0,f3=0,f4=0,a1=1,b1=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    if(a==b){cout<<1;f1=1;}
    else{cout<<0;}
    cout<<0;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        b1=1;
    }
    if(f1&&f2&&a1==b1){
        f3=1;
        cout<<1;
    }
    else cout<<0;
    if(f1&&f2&&f3&&s1[2]-1==s2[2]||s1[2]+1==s2[2]){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
