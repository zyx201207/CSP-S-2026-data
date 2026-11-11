#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int x;
    char c;
    string s;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        if(x>500) return 0;
        for(int j=0;j<x;j++){
            s+=c;
        }
    }
    int ssi=s.size();
    int zs=ssi/2;
    int ans=0;
    string news=s;
    for(int i=0;i<zs;i++){
        if(s[i]!=s[ssi-i-1]){
            news[ssi-i]==s[i];
            ans++;
        }
    }
    cout<<ans;
return 0;
}

