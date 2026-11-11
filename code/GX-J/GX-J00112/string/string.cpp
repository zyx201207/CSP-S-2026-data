#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m[100005],a=0;
    string s[100005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        if(s[1]==s[i]){
            a+=1;
        }
    }
    if(a==n){
        cout<<0;
        return 0;
    }

    return 0;
}
