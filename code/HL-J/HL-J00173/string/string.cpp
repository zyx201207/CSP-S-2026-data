#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    cin>>n;
    string x;
    for (int i=1;i<=n;i++){
        long long a;
        char b;
        cin>>a>>b;
        x.append(a,b);
    }
    int l=0,r=x.size()-1;
    while(l<=r){
        if (x[l]!=x[r]){
            ans++;
        }
        l++,r--;
    }
    cout<<ans;

    return 0;
}
