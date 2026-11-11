#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    long long n,a;
    string s,c;
    cin>>n;
    while(n--){
        cin>>a>>s;
        for(int i=1;i<=a;i++){
            c+=s;
        }
    }
    long long len=c.size();
    for(int i=0;i<c.size();i++){
        if(c[i]!=c[len-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
