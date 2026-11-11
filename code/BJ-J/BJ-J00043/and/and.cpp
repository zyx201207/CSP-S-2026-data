#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    vector<long long> js;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2==1) js.push_back(a[i]);
    }
    long long ans=12;
    if(js.size()>=m){
        sort(js.begin(),js.end());
        ans=js[m-1];
        for(int j=m-1;j<js.size();j++){
            ans&=js[j];
        }
    }
    cout<<ans<<'\n';
    return 0;
}