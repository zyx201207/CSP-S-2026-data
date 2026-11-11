#include <bits/stdc++.h>
using namespace std;
string s="";
int sl=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        char c;
        cin>>op>>c;
        for(int j=1;j<=op;j++) s+=c;
        sl+=op;
    }
    for(int i=1;i<=sl/2;i++){
        if(s[i-1]!=s[sl-i]) ans++;
    }
    cout<<ans;
    return 0;
}
