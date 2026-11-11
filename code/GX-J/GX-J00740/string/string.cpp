#include<bits/stdc++.h>
using namespace std;
string s,bi;
int ans=0,n,ai,s_long=0;
void f(int a1,string b)
{
    for(int i=1;i<=a1;i++){
        s+=b;s_long++;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ai>>bi;
        f(ai,bi);
    }
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[s_long-i-1]){
            ans++;
        }
    }
    cout<<ans;
}
