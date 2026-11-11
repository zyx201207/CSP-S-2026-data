#include<bits/stdc++.h>
using namespace std;
long long n,ans;
unsigned long long d;
stack <char>m[2];
string s;
struct node{
    long long t;
    string a;
}p[200005];
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].t;
        cin>>p[i].a;
        d+=p[i].t;
        for(int j=1;j<=p[i].t;j++) s+=p[i].a;
    }
    bool same=0;
    for(int i=2;i<=n;i++){
        if(p[i].a!=p[i-1].a){
            same=1;
            break;
        }
    }
    if(!same){
        cout<<0;
        return 0;
    }
    if(d%2!=0){
        d--;
        for(int i=0;i<=(d/2)-1;i++) m[0].push(s[i]);
        for(int i=s.size()-1;i>d/2;i--) m[1].push(s[i]);
        while(d--&&!m[0].empty()&&!m[1].empty()){
            char a1=m[0].top(),b1=m[1].top();
            if(a1!=b1) ans++;
            m[0].pop();
            m[1].pop();
        }
    }
    else{
        for(int i=0;i<=(d/2)-1;i++) m[0].push(s[i]);
        for(int i=s.size()-1;i>d/2;i--) m[1].push(s[i]);
        while(d--){
            char a1=m[0].top(),b1=m[1].top();
            if(a1!=b1) ans++;
            m[0].pop();
            m[1].pop();
        }
    }
    cout<<ans;
    return 0;
}
