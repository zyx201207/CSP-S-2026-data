#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long m=0;
    cin>>n;
    string s=" ";
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        m+=(a/2);
        while(a--){
            s+=b;
        }
    }
    long long ans=0;
    for(int i=1;i<=m;i++){
        if(s[i]!=s[m*2-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
