#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int c3=0,c4=0;
    int s3=0,s4=0;
    int n,m;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')m=1;
    else{
        m=2;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')n=1;
    else{
        n=2;
    }
    for(int i=0;i<2;i++){
        c3*=10;
        c4*=10;
        s3*=10;
        s4*=10;
        c3+=c1[i]-'0';
        c4+=c2[i]-'0';
        s3+=s1[i]-'0';
        s4+=s2[i]-'0';
    }
    if(c3==c4)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(s3==s4)cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;

    }
    if(n==m)cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if(s1[2]==(s2[2]+1)||s1[2]==(s2[2]-1)){
        cout<<1;
    }else{
        if(n==2){
            cout<<1;
            return 0;
        }
        cout<<0;
    }
    return 0;
}
