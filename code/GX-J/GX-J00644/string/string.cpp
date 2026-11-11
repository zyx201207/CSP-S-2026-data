#include<bits/stdc++.h>
using namespace std;
struct st{
    long long x;
    char w;};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<st>s;
    long long n,ans=0,x1,a;
    char w1;
    st l={0,' '};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x1>>w1;
        l.x=x1;
        l.w=w1;
        s.push_back(l);}
   // for(int i=0;i<s.size();i++){
  //      cout<<s[i].x<<' '<<s[i].w<<'\n';}
    for(int i=0;i<s.size()/2;i++){
        if(s[i].w!=s[n-i-1].w||s[i].x!=s[n-i-1].x){
 //           cout<<s[i].x<<' '<<s[n-i-1].x<<'\n';
            if(s[i].w==s[n-i-1].w){
                a=abs(s[i].x-s[n-i-1].x);
                if(s[i+1].x<=s[n-i-2].x){
                    s[i+1].x+=a;}
                else{
                    s[n-i-2].x-=a;}}
            else{
                a=max(s[i].x,s[n-i-1].x);
                if(s[i+1].x<=s[n-i-2].x){
                    s[i+1].x+=abs(s[i].x-s[n-i-1].x);}
                else{
                    s[n-i-2].x-=abs(s[i].x-s[n-i-1].x);}}}
        ans+=a;}
    cout<<ans/2;}

