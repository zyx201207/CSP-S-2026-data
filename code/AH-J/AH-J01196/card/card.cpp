#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int b[500005]={};
        int len=0;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=len;k++){
                if(b[k]==a[j]){
                    len=k-1;
                    break;
                }
            }
            b[++len]=a[j];
        }
        for(int j=1;j<=len;j++){
            cnt[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
