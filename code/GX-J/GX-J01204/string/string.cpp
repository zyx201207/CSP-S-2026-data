#include <bits/stdc++.h>
using namespace std;
string s;
int f[1000006],ans=0,k,g[1000006];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        cin>>f[i];
        if(f[i]>='a'&&f[i]<='z'){
            k++;
            g[k]=f[i];

        }
        for(int i=1;i<=k;i++){
            ans++;
        }

    }
    cout<<ans;
    return 0;
}
