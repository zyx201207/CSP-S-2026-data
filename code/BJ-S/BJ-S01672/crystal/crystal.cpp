#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int countt=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        m-=countt*(a[i+1]-a[i]);
        if(m<0){
            break;
        }
        countt++;
    }
    cout<<countt;
    return 0;
}
