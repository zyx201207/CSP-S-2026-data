#include<bits/stdc++.h>
using u=unsigned long long;
using namespace std;
int n,x;
u ans;
bool ok=true;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x>>c;
        string tmp(x,c);
        s+=tmp;
    }
    u sz=s.size()/2;
    for(u i=1;i<=sz;++i)
        if(s[i-1]!=s[s.size()-i])
            ans++;
    cout<<ans;
    return 0;
}
