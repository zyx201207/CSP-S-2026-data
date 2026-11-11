#include <bits/stdc++.h>
using namespace std ;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int w=0;
    for(int x=1;x<=n;x++){
        unsigned int a;
        char c;
        cin>>a>>c;
        for(unsigned int i=1;i<=a;i++){
            s[w]=c;
            w++;
        }
    }
    int ans=0;
    for(int i=0;i<(w-1)/2;i++){
        if(s[i]!=s[w-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
