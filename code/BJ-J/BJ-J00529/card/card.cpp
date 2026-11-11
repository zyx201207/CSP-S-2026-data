#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int n,m,a[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=m;i++){
        int pre[N]={0},b[N],cnt=0,ans=0; //pre[i]记录的是点数i上一次出现的位置
        bool vis[N]={0};
        for(int j=i;j<=n;j++){
            if(pre[a[i]]){
                cnt=pre[a[i]]; //这里pre不用改，因为下一个已经填上了
            } else {
                b[++cnt]=a[i];
                pre[a[i]]=cnt;
            }
            for(int k=1;k<=cnt;k++){
                if(b[k]==i){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" ";
    }
}
