#include<bits/stdc++.h>
using namespace std;
const int N=110;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s[N];
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    if(s[0]==s[2])cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    string num1,num2;
    for(char c:s[1])
        if(isdigit(c))num1+=c;
    for(char c:s[3])
        if(isdigit(c))num2+=c;
    if(num1==num2)cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    char ch1,ch2;
    ch1=s[1][2];
    ch2=s[3][2];

    bool flag=false;
    if(ch1=='D'&&ch2=='F')flag=true;
    else if(ch1=='F'&&ch2=='D')flag=true;
    else if((ch1=='C'||ch1=='B'||ch1=='A')&&(ch2=='A'||ch2=='B'||ch2=='C'))flag=true;
    cout<<flag;
    if(!flag){
        cout<<0;
        return 0;
    }
    if(ch1==ch2){
        cout<<0;
        return 0;
    }
    if(ch1+1==ch2||ch1-1==ch2)cout<<1;
    else cout<<0;
    return 0;
}