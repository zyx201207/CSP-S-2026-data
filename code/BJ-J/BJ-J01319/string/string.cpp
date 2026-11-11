#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s=s+c;
    }
    int t=s.length(),ans=0;
    for(int i=0;i<s.length();i++)
        ans+=(s[i]!=s[t-i+1]);
    cout<<ans;
    return 0;
}
