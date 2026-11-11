#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],last[500005],nxt[500005],iscover[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(last[a[i]]) nxt[last[a[i]]]=i,last[a[i]]=i;
        else last[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(nxt[i]==0) nxt[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            iscover[j]=0;
        }
        for(int j=i;j<=n;j++){
            iscover[j]+=iscover[j-1];
            if(iscover[j]>0) continue;
            iscover[j]++;
            iscover[nxt[j]]--;
        }
        for(int j=i;j<=n;j++){
            /*if(j<i){
                cout<<"  ";
                continue;
            }
            cout<<iscover[j]<<" ";*/
            if(iscover[j]==0) ans[a[j]]++;
        }
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
