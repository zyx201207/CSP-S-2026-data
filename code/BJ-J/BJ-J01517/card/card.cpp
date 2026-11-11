#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,maxn=0;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    int ans[maxn+1]={0};
    for(int i=1;i<n;i++){
        int pos[maxn+1]={0};
        int k=1,card[maxn+1]={0};
        for(int j=i;j<=n;j++){
            if(pos[a[j]]){
                for(int s=k;s>pos[a[j]];s--){
                    pos[card[s]]=0;
                    card[s]=0;
                }
                k=pos[a[j]]+1;
            }
            else {
                pos[a[j]]=k;
                card[k++]=a[j];
            }
        }
        for(int j=1;j<=maxn;j++){
            if(pos[j]){
                ans[j]++;
            }
        }
    }
    ans[a[n]]++;
    for(int i=1;i<=maxn;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

