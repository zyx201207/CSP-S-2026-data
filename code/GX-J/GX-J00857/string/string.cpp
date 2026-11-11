#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0;
    char c;string s;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x>>c;l+=x;
        for(int j=0;j<x;j++){
            s=s+c;
        }
    }
    string d=s;
    reverse(d.begin(),d.end());
    int ans=0;
    for(int i=0;i<l/2+1;i++){
        if(d[i]!=s[i]){
            s[i]=d[i];
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
