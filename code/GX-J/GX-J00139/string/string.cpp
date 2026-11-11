#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
    long long n;
    string s;
}a[200005];
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    string ans="";
    for(int i=1;i<=t;i++){
        cin>>a[i].n>>a[i].s;
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=a[i].n;j++){
            ans+=a[i].s;
        }
    }
    const int sz=ans.size();
    long long num=0;
    if(sz&1){
        for(int i=0;i<(sz-1)/2;i++){
            if(ans[i]==ans[sz-1-i]) continue;
            else num++;
        }
    }
    else{
        if(ans[sz/2]!=ans[sz/2-1]) num++;
        for(int i=0;i<sz/2-1;i++){
            if(ans[i]==ans[sz-1-i]) continue;
            else num++;
        }
    }
    cout<<num;
}

