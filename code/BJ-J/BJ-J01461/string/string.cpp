#include<bits/stdc++.h>
using namespace std;
int n,sz;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string t;
        cin>>a>>t;
        sz+=a;
        for(int j=1;j<=a;j++){
            s=s+t;
        }
    }
    int cnt=0;
    for(int i=0;i<sz/2;i++){
        if(s[i]!=s[sz-i-1])cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
