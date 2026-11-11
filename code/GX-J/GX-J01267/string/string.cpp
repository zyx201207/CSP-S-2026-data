#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,sum;
struct node{
    int a,s,e;
    char c;
}s[200005];
string os,ns;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        sum+=s[i].a;
        for(int j=1;j<=s[i].a;j++){
            os+=s[i].c;
        }
    }
    for(int i=0;i<os.size();i++){
        ns+=os[sum-i-1];
    }
    for(int i=0;i<os.size()/2;i++){
        if(ns[i]!=os[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
