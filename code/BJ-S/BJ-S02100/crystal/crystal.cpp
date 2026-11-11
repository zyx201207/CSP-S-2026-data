#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010],plu[500010];
long long usd;
long long maxcnt=-1;
void dfs(){
    if(usd==m){
        long long cnt[100000]={0};
        for(int i=1;i<=n&&(a[i]+plu[i])>=0;i++){
            cnt[a[i]+plu[i]]++;
            maxcnt=max(maxcnt,cnt[a[i]+plu[i]]);
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(plu[i]<m-1){
            plu[i]++;
            usd++;
            dfs();
            plu[i]--;
            usd--;
        }
    }

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs();
    cout<<maxcnt;
    return 0;
}
