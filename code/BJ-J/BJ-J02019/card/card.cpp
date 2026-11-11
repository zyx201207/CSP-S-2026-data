#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],last[500005],f[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int j=i-1;
        while(j>=1){
            if(last[a[j]]>i){
                f[i]=j;
                break;
            }
            j--;
        }
        if(f[i]==0){
            f[i]=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]!=INT_MAX){
            ans[a[i]]+=(i-f[i]);
        }
        else{
            ans[a[i]]=max(ans[a[i]],(long long)i);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
