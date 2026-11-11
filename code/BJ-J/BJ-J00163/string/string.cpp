#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
char lst;
bool is=1;
int ans;

bool ish(string s){
    bool ok=1;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i])ok=0;
    }return ok;
}

string s;
int w;
int mx=-1;
signed main(signed argc,char**argv){
    ios::sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int u;
        char v;
        cin>>u>>v;
        if(i==1)lst=v;
        if(lst!=v)is=0;
        s+=v;
        w+=u;
        mx=max(mx,u);
    }
    if(is||ish(s))return cout<<0,0;
    if(w%2!=0)ans++;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1])ans++;

    }cout<<ans*mx;
    return 0;
}
