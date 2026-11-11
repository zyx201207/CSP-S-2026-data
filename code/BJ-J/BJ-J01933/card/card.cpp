#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool vis[300005];
int lst[300005],cnt[300005];
int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ii,jj;
    for(ii=1,jj=1;jj<=n;ii++,jj++){
        cin>>a[ii];
        cnt[a[ii]]++;
        if(a[ii]==a[ii-1]) ii--;
    }
    for(int i=--ii;i>=1;i--){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            lst[a[i]]=i;
        }

    }
    for(int i=1;i<=m;i++){
        for(int j=lst[i];j<=ii;j++){
            if(j==lst[a[j]]){
                ans[a[j]]+=cnt[i];
            }
            else{
                j=lst[a[j]]-1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
//luogu uid:1426874 will_be_there
//BJ似乎没有迷惑行为大赏
//有的话加我一个
