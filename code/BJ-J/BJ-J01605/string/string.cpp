#include<bits/stdc++.h>
using namespace std;
struct st{
    long long s;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n;
    cin>>n;
    queue<st>v;
    stack<st>rv;
    for(int i=1;i<=n;i++){
        long long x;
        char s;
        cin>>x>>s;
        v.push({x,s});
        rv.push({x,s});
    }
    unsigned long long ans=0;
    while(!v.empty()||!rv.empty()){
        st qf=v.front(),sf=rv.top();
        if(qf.c!=sf.c){
            ans+=min(qf.s,sf.s);
            if(qf.s>sf.s){
                rv.pop();
                v.front().s-=sf.s;
            }else if(qf.s<sf.s){
                v.pop();
                rv.top().s-=qf.s;
            }else{
                v.pop();
                rv.pop();
            }
        }
        else{
            if(qf.s>sf.s){
                rv.pop();
                v.front().s-=sf.s;
            }else if(qf.s<sf.s){
                v.pop();
                rv.top().s-=qf.s;
            }else{
                v.pop();
                rv.pop();
            }
        }
    }
    cout<<ans/2;
    return 0;
}

