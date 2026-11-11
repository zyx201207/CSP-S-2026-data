#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[300005];
map<int,int>ma;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(ma.find(a[i])!=ma.end())b[ma[a[i]]]=i;
        ma[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]==0&&a[j]<=m)ans[a[j]]++;
            else if(b[j])j=b[j]-1;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
