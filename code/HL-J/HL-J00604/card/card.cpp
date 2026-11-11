#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],last[500010],now[500010],ans[300010],st[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=n;i>=1;i--){
        last[i]=now[a[i]];
        now[a[i]]=i;
    }

    for(int i=1;i<=n;i++){
        fill(st,st+m+1,1);
        for(int j=i;j<=n;j++){
            if(last[j]!=0){
                j=last[j]-1;
                continue;
            }
            ans[a[j]]+=st[a[j]];
            st[a[j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}



