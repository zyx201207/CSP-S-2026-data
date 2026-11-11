#include<bits/stdc++.h>
using namespace std;
long long n,a[214514],c,q;
string s,d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    d[1]=s[1];
    for(int i=1;i<=n;i++){
        if(d[1]==s[i])c++;
    }
    for(int i=1;i<=n;i++){
        q+=a[i];
    }
    if(c==n) cout<<0;
    else cout<<q/2;
    return 0;
}
