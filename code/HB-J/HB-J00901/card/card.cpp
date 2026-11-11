#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            flag=0;
        }
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]&&a[i]==1) cnt[1]++;
            else if(a[i]==a[n]&&a[i]==2) cnt[2]++;
            else{
                cnt[1]++;
                cnt[2]++;
            }
        }
        cout<<cnt[1]<<' '<<cnt[2];
        return 0;
    }
    if(flag){
        for(int i=1;i<=n;i++){
            cnt[a[i]]=max(cnt[a[i]],i);
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            if(t[a[j]]){
                for(int k=t[a[j]]+1;k<j;k++){
                    if(t[a[k]]==k) t[a[k]]=0;
                }
            }
            else{
                t[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(t[j]){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
