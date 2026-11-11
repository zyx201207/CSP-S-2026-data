#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,s1;
char s3;
int c2,s2;
char s4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>s3>>c2>>s2>>s4;
    if(c1!=c2){
        cout<<"0000";
        exit(0);
    }cout<<1;
    if(s1!=s2){
        cout<<"000";
        exit(0);
    }cout<<1;
    if((s3=='F'&&s4=='D')||(s3=='D'&&s4=='F')){
        cout<<"11";
        exit(0);
    }if((s3=='C'&&s4=='B')||(s3=='B'&&s4=='C')||(s3=='B'&&s4=='A')||(s3=='A'&&s4=='B')||(s3=='C'&&s4=='A')||(s3=='A'&&s4=='C')){
        cout<<"1";
    }else{
        cout<<"0";
    }if((s3=='C'&&s4=='B')||(s3=='B'&&s4=='C')||(s3=='B'&&s4=='A')||(s3=='A'&&s4=='B')){
        cout<<"1";
        exit(0);
    }cout<<0;
    return 0;
}
