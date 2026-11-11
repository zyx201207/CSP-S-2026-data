#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
const int maxm=5e5+10;
int n,m;
int a[maxm];
int tong[maxn];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    vector<int> table;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        table.clear();
        for(int j=i;j<=n;j++){
            auto it=find(table.begin(),table.end(),a[j]);
            if(it==table.end()){
                table.push_back(a[j]);
            }
            else{
                table.erase(it,table.end());
                table.push_back(a[j]);
            }
        }
        for(auto it:table) tong[it]++;
    }
    for(int i=1;i<=m;i++) cout<<tong[i]<<" ";
    cout<<'\n';
    return 0;
}