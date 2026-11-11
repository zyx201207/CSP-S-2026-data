#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
int a[200005];
bool vis[200005];
int t[32];
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vis[i]=1;
        for(int j=29;j>=0;j--){
            if((a[i]&(1<<j)))
            t[j]++;
        }
    }
    //for(int j=0;j<=29;j++)cout<<t[j]<<" ";
    for(int j=29;j>=0;j--){
        if(t[j]>=m){
            ans+=(1<<j);
            for(int i=1;i<=n;i++){
                if(vis[i]==1&&(a[i]&(1<<j))==0){
                    vis[i]=0;
                    //cout<<j<<" "<<i<<endl;
                    for(int k=29;k>=0;k--){
                        if((a[i]&(1<<k)))
                        t[k]--;
                    }
                }
            }
            /*cout<<j<<endl;
            for(int k=0;k<=5;k++)cout<<t[k]<<" ";
            cout<<endl;*/
        }
    }
    printf("%lld",ans);
    return 0;
}
