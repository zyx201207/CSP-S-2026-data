#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    vector<int>v;
    cin>>n>>m;
    long long x;
    for(int i=0;i<n;++i){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int sum=v[v.size()-1];
    for(;m>=0;){
        sum=sum&v[v.size()-m-1];
        m--;
    }
    cout<<sum;
    return 0;
}
