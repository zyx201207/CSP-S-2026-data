#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt=0,ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof(b));
        cnt=0;
        for(int j=i;j<=n;j++){
            for(int k=1;k<=cnt;k++){
                if(b[k]==a[j]){
                    for(int h=k;h<=cnt;h++){
                        b[k]=0;
                    }
                    cnt=k-1;
                }
            }
            ++cnt;
            b[cnt]=a[j];
        }
        for(int j=1;j<=cnt;j++){
            ++ans[b[j]];
        }
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    return 0;
}
