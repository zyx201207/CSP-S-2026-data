#include <bits/stdc++.h>
using namespace std;
int n,a,L,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>a>>c;
        L+=a;
        while(a--){
            s+=c;
        }
    }
    for(int i = 0;i<L/2;++i){
        if(s[i]!=s[L-i-1]){
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
