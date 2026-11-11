#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool fa=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i-1]>a[i]){
            fa=0;
        }
    }
    if (fa){
        for (int i=n;i>=1;i--){
            ans[a[i]]=max(ans[a[i]],i);
        }
        for (int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
        return 0;
    }
    for (int i=1;i<=n;i++){
        vector<int> v;
        map<int,int> mp;
        for (int j=i;j<=n;j++){
            if (mp[a[j]]){
                for (int k=j-1;k>mp[a[j]];k--){
                    mp[a[k]]=0;
                }
                for (int k=v.size()-1;v[k]!=a[j];k--){
                    v.pop_back();
                }
                v.pop_back();
            }
            mp[a[j]]=j;
            v.push_back(a[j]);
        }
        for (int j=0;j<v.size();j++){
            ans[v[j]]++;
        }
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
