#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,n,m;
string s1,s2;
char o,p;
bool check(char k,char l){
    if(k=='A'&&(l=='B'||l=='C'))return 1;
    if(k=='B'&&(l=='A'||l=='C'))return 1;
    if(k=='C'&&(l=='A'||l=='B'))return 1;
    if(k=='D'&&l=='F')return 1;
    return 0;
}
bool check1(char k,char l){
    if(k=='A'&&l=='B')return 1;
    if(k=='B'&&(l=='A'||l=='C'))return 1;
    if(k=='C'&&l=='B')return 1;
    if(k=='D'&&l=='F')return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    n=(s1[0]-'0')*10+(s1[1]-'0'),m=(s2[0]-'0')*10+(s2[1]-'0'),o=s1[2],p=s2[2];
    if(a==b)cout<<1;
    else cout<<0;
    if(a==b&&n==m)cout<<1;
    else cout<<0;
    if(a==b&&n==m&&check(o,p))cout<<1;
    else cout<<0;
    if(a==b&&n==m&&check1(o,p))cout<<1;
    else cout<<0;
    return 0;
}