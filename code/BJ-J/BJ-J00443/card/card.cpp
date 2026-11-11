#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        int now=0;
        for(int i=k;i<=n;i++){
            int f=0;
            for(int j=1;j<=now;j++){
                if(b[j]==a[i]){
                    now=j;
                    f=1;
                    break;
                }
            }
            if(!f)b[++now]=a[i];
            //cout<<i<<":"<<now<<endl;
        }
        for(int i=1;i<=now;i++){
            ans[b[i]]++;
            //cout<<b[i]<<endl;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
