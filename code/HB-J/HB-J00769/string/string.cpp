#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
vector<char> v;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        m+=x;
        while(x--) v.push_back(y);
    }
    int l=0,r=m-1;
    while(l<=r){
        if(v[l]!=v[r]) ans++;
        l++;r--;
    }
    cout<<ans;
    return 0;
}
