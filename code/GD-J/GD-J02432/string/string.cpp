#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t,ans=0;
    cin>>t;
    string a;
    for(int i=1;i<=t;i++){
        int n;
        char b;
        cin>>n>>b;
        for(int i=1;i<=n;i++){
            a+=b;
        }
    }

    for(int i=0;i<=((a.size())/2)-1;i++){
        if(a[i]!=a[a.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
