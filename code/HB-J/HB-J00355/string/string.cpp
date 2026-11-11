#include<bits/stdc++.h>
using namespace std;
string s,s2;
long long x,ans=0,n;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        for(int i=1;i<=x;i++){
            s+=a;
        }
    }
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        s2+=s[i];
    }
    for(int i=0;i<len;i++){
        if(s2[i]!=s[i]){
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}
