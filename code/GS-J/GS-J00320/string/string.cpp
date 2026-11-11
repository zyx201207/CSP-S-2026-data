#include <bits/stdc++.h>
using namespace std;

char c;
int n,num,ans,long_s;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        cin>>c;
        for (int j=1;j<=num;j++) s[i]=c;
        long_s++;
    }
    for(int i=0;i<=n;i++){
        if(s[i]!=s[long_s-i])
            ans++;
    }
    cout<<ans;
    return 0;
}
