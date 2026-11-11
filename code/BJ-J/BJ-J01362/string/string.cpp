#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
char c;
ll t,n,len,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
       cin>>n>>c;
       for(int i=len;i<=len+n;i++){
            s[i]=c;
       }
       len+=n;
    }
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-1-i]){
            ans++;
        }
    }
    cout<<ans;
}
