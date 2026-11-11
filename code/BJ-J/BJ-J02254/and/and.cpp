#include<bits/stdc++.h>
using namespace std;
vector<long long>v(200010);
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    long long ans;
    for(int i=0;i<n;++i)cin>>v[i];
    sort(v.begin(),v.end(),less<long long>());
    ans=v[0];
    for(int i=1;i<m;++i)ans&=v[i];
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
