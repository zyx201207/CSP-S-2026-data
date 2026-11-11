#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long>v;
    long long x;
    for(long long i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    long long sum=0,i=0,o;
    while(m>=0&&i<=n){
        o=v[i+1]-v[i];
        m-=(o*(i+1));
        i++;
    }
    if(i>=n){
        cout<<n;
        return 0;
    }
    cout<<i;
    return 0;
}
