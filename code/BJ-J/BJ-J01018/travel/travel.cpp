#include<bits/stdc++.h>
using namespace std;
int n;
char s1[5],x1[5],s2[5],x2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1[0]>>s1[1];
    for(int i=0;i<3;i++){
        cin>>x1[i];
    }
    cin>>s2[0]>>s2[1];
    for(int i=0;i<3;i++){
        cin>>x2[i];
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(x1[0]==x2[0]&&x1[1]==x2[1]) cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }

    if(x1[2]=='C'||x1[2]=='B'||x1[2]=='A'){
        if(x2[2]=='D'||x2[2]=='F'){
            cout<<0<<0;
            return 0;
        }
        else cout<<1;
    }

    if(x1[2]=='D'||x1[2]=='F'){
        if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
            cout<<0<<0;
            return 0;
        }
        else cout<<1;
    }

    if(x2[2]+1==x1[2]||x2[2]-1==x1[2]) cout<<1;
    else cout<<0;
    return 0;
}
