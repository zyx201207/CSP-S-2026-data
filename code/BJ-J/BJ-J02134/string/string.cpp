#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,num=0,a[500000];
    string s;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++) a[++num]=c;
    }
    for(int i=1;i<=s.size();i++){
        if(a[s.size()-i+1]!=a[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}