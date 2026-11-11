#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t;
    cin>>n;
    string s[1000005];
    char r;
    int len=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>t>>r;
        len+=t;
        if(s[i]==s[len-i-1]){
            ans+=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=s[len-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
