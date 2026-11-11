#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int>v(n+1),b(m+1),lap(m+1,-1),ans(m+1,-1);
    b[0]=0;
    for(int i=1;i<=n;++i){
        cin>>v[i];
        if(-1==lap[v[i]])lap[v[i]]=i;
        if(-1==ans[v[i]])ans[v[i]]=i;
    }
    for(int i=1;i<=n;++i)b[i]=ans[i]-b[i-1];
    for(int i=1;i<=n;++i){
        --b[lap[v[i]]];
        ++b[(lap[v[i]]=i)+1];
    }
    for(int i=1;i<=m;++i)cout<<(b[i]+=b[i-1])<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
