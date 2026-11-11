#include <bits/stdc++.h>
using namespace std;
long long c,t,a[1000008],ans,n,d,f[308],cnt[308],last[308];
long long w[20]={1};
void dfs(int x,int deep,int num){
    if(deep>f[x]){
        return;
    }
    if(deep==f[x]&&num^last[x]!=0){
        cnt[x]++;
    }
    if(deep<f[x]){
        f[x]=deep;
        cnt[x]=1;
        last[x]=num;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]-a[x]<=d){
            dfs(i,deep+1,num+w[x]);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>=11&&c<=12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            ans=0;
            long long can=d/(a[2]-a[1]);
            if(can==0||can==1){
                cout<<0<<endl;
                continue;
            }
            for(int i=1;i<=n;i++){
                long long last=min(n,i+can*2-1);
                ans+=(last-min(n,i+can+can-1-1));
            }
            cout<<ans<<endl;
        }
    }
    if(c==1||c==2){
        for(int i=1;i<=15;i++){
            w[i]=w[i-1]*2;
        }
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            ans=0;
            for(int i=1;i<=n;i++){
                memset(f,0x3f,sizeof(f));
                memset(cnt,0,sizeof(cnt));
                memset(last,0,sizeof(last));
                dfs(i,0,0);
                for(int j=i+1;j<=n;j++){
                    if(cnt[j]==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
