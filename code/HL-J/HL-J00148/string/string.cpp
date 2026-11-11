#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans;
    cin>>n;
    vector<char>s;
    long long sum,ls,rs,li,ri;
    sum=ls=rs=li=ri=0;
    char b[200005]={};
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        while(a--)s.push_back(b);
    }
    if(s.size()%2){
        for(int i=1;i<=s.size()/2;i++){
            if(s[s.size()/2+i]!=s[s.size()/2-i]){
                ans++;
            }
        }
    }
    else{
        for(int i=0;i<s.size()/2;i++){
            if(s[s.size()/2+i]!=s[s.size()/2-1-i])ans++;
        }
    }
    cout<<ans;
}
