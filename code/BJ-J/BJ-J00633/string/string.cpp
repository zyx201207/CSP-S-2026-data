#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int len=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
            len++;
        }
    }
    s=' '+s;
    long long ans=0;
   for(int i=(len+1)/2;i>=1;i--){
        if(s[i]!=s[len+1-i]) ans++;
   }
   cout<<ans;
    return 0;
}
