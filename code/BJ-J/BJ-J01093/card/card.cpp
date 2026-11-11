#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mp[500005],ans[500005];
bool vis[500005];
bool b=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]<a[i-1])b=0;
    }
    if(b){
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
        }
        long long ansx=0;
        for(int i=1;i<=m;i++){
            ansx+=mp[i];
            cout<<ansx<<" ";
        }
        return 0;
    }
    for(int i=n;i>=1;i--){
        for(int k=1;k<=m;k++)mp[k]=0;
        for(int k=1;k<=n;k++)vis[k]=0;
        for(int k=i;k<=n;k++){
            mp[a[k]]++;
            if(mp[a[k]]>1){
                for(int j=k-1;j>=i;j--){
                    if(vis[j])continue;
                    mp[a[j]]--;
                    vis[j]=1;
                    if(a[j]==a[k])break;
                }
            }
        }
        for(int k=1;k<=m;k++){
            ans[k]+=mp[k];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}