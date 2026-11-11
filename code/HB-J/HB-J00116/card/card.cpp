#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a,table,ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    ans.resize(m);
    for(int i = 1;i<=n;++i){
        cin>>a[i];
    }
    for(int i = 1;i<=n;++i){
        table.resize(0);
        for(int j = i;j<=n;++j){
            table.push_back(a[j]);
            for(int k = 0;k<table.size()-1;++k){
                if(table[k]==a[j]){
                    table.resize(k+1);
                    break;
                }
            }
        }
        for(int j:table){
            ++ans[j-1];
        }
    }
    for(int i:ans){
        cout<<i<<' ';
    }
    return 0;
}
