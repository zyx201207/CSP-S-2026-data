#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;char c;string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(int j=1;j<=x;j++)s+=c;
    }
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
           cout<<2;
           return 0;
        }
        l++,r--;
    }
    cout<<0;
    return 0;
}
