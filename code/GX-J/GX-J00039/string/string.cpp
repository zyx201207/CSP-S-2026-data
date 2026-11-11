#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ss=0,sss=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;char r;
        cin>>t>>r;ss+=t;
        for(int j=1;j<=t;j++)s+=r;
    }
    for(int i=0;i<ss/2;i++){
        if(s[i]!=s[ss-1-i])sss+=1;
    }
    cout<<sss;
    return 0;
}
