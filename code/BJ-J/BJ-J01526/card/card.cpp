#include<bits/stdc++.h>
using namespace std;

vector<int>l[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[500005];
    int ans[300005];

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[a[j]]++;
            j=l[a[j]][l[a[j]].size()-1];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

