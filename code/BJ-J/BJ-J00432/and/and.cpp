#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1;bool vis[200005];
void dfs(int step,int sum,int ii){
    if(step==m+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==ii)continue;
        int fsum=sum;
        fsum&=a[i];
        dfs(step+1,fsum,ii);
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=20){
        for(int i=1;i<=n;i++){
            dfs(1,a[i],i);
        }
    }else if(n<=2000){
        if(m==1){
            for(int i=1;i<=n;i++)
            {
                ans=max(ans,a[i]);
            }
        }else if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans&=a[i];
            }
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;i++){
                    int sum=(a[i]&a[j]);
                    ans=max(ans,sum);
                }
            }
        }
    }else{
        if(m==n-1){
            for(int i=n;i>0;i--){
                if(i==1)int sum=a[2];
                int sum=a[1];
                vis[i]==true;
                for(int j=1;j<=n;j++){
                    if(vis[j]!=true){
                        sum&=a[j];
                    }
                }
                ans=max(ans,sum);
            }
        }
    }

    cout<<ans;
    return 0;
}
