#include<bits/stdc++.h>
using namespace std;
bool cmp(unsigned long long a,unsigned long long b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n,m;
    cin>>n>>m;
    vector<unsigned long long>v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),cmp);
    unsigned long long ans=v[0];
    for(int i=0;i<m;i++)ans&=v[i];
    cout<<ans;
    return 0;
}
