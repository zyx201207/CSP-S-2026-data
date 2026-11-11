#include<bits/stdc++.h>
using namespace std;
int c[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    string s,s1;
    cin>>m>>s>>n>>s1;
    if(m==n){
        c[1]=1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s[0]==s1[0]&&s[1]==s1[1]){
        c[2]=1;
    }
    else{
        cout<<"1000";
        return 0;
    }
    if(s[2]>='A'&&s[2]<='C'&&s1[2]>='A'&&s1[2]<='C'){
        c[3]=1;
        if(s[2]=='A'&&s1[2]=='B'){
            c[4]=1;
        }
        else if(s[2]=='B'&&s1[2]=='C'){
            c[4]=1;
        }
        else if(s[2]=='B'&&s1[2]=='A'){
            c[4]=1;
        }
        else if(s[2]=='C'&&s1[2]=='B'){
            c[4]=1;
        }
        else if(s[2]=='D'&&s1[2]=='F'){
            c[4]=1;
        }
        else if(s[2]=='F'&&s1[2]=='D'){
            c[4]=1;
        }
        else {
            cout<<"1110";
            return 0;
        }
    }
    else if(s[2]>='D'&&s[2]<='F'&&s1[2]>='D'&&s1[2]<='F'){
        c[3]=1;
        if(s[2]=='A'&&s1[2]=='B'){
            c[4]=1;
        }
        else if(s[2]=='B'&&s1[2]=='C'){
            c[4]=1;
        }
        else if(s[2]=='B'&&s1[2]=='A'){
            c[4]=1;
        }
        else if(s[2]=='C'&&s1[2]=='B'){
            c[4]=1;
        }
        else if(s[2]=='D'&&s1[2]=='F'){
            c[4]=1;
        }
        else if(s[2]=='F'&&s1[2]=='D'){
            c[4]=1;
        }
        else {
            cout<<"1110";
        }
    }
    else{
        cout<<"1100";
        return 0;
    }
    cout<<"1111";
    return 0;
}

