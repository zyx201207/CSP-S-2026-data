#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int a[N],b[N],n,m,ans=0;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) b[i]=a[i];
    int nowcnt=n;
    for(int j=31;j>=1;j--){
        int cnt=0;
        bool vis[N]={0};
        for(int i=1;i<=nowcnt;i++){
            if(b[i]&(1<<(j-1))){
                cnt++;
                vis[i]=1;
            }
        }
        if(cnt>=m){
            ans|=(1<<(j-1));
            int poscnt=0,c[N];
            for(int i=1;i<=nowcnt;i++){
                if(vis[i]) c[++poscnt]=b[i];
            }
            for(int i=1;i<=poscnt;i++) b[i]=c[i];
            nowcnt=poscnt;
        } else continue;
    }

    cout<<ans;
    return 0;
}
