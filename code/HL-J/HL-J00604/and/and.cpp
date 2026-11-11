#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mod=(1<<30)-1,ans;
vector<long long> b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=mod^a[i];
        //cout<<a[i]<<" ";
        b.push_back(a[i]);
    }
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=0;i<m;i++){
        ans|=b[i];
    }
    cout<<(mod^ans);
    return 0;
}


