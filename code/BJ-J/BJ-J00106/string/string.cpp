#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T;
    string s="";
    cin>>T;
    long long sz=0;
    while(T--){
        long long n;
        char c;
        cin>>n>>c;
        for(long long i=1;i<=n;i++)s+=c;
        sz+=n;
    }
    sz/=2;
    long long ans=0;
    string s1="";
    for(long long i=0;i<sz;i++)s1+=s[i];
    string s2="";
    for(long long i=s.size()-1;i>sz;i--)s2+=s[i];
    for(long long i=0;i<sz;i++){
        if(s1[i]!=s2[i])ans++;
    }
    cout<<ans;
    return 0;
}
