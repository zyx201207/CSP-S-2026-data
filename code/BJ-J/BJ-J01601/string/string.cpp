#include<bits/stdc++.h>
using namespace std;
int sum,ans,len;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int le;char ee;cin>>le>>ee;
        for(int j=1;j<=le;j++){
            s[j+sum]=ee;len++;
    }sum+=le;}
    sum=len/2;
    for(int i=sum;i;i--){
        if(s[i]!=s[len-i+1])ans++;
        sum--;
    }cout<<ans;

}
