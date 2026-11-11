#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n,0);
    vector<long long> cnt(m+1,0);
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        vector<long long> vis(m+1,-1);
        for(long long j=i;j<n;j++){
            cnt[a[j]]++;
            if(vis[a[j]]!=-1){
                for(long long k=vis[a[j]];k<j;k++){
                    if(vis[a[k]]==k)cnt[a[k]]--;
                    vis[a[k]]=-1;
                }
            }
            vis[a[j]]=j;
        }
    }
    for(long long i=1;i<=m;i++)cout<<cnt[i]<<" ";
    fclose(stdin);
    fclose(stdout);
}
