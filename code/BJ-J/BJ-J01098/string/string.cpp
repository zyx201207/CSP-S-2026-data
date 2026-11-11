#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        m+=a;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    s=" "+s;
    for(int i=1;i<=m/2;i++){
        if(s[i]!=s[m-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
