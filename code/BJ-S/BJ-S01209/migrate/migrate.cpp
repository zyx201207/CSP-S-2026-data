#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,maxn[5005],a[5005],p,ans,maxi,cnt;
void dfs(int x,int ymy,int nx){
    if(ymy==maxi){
        if(x==nx){
            cnt+=1;
        }
    }else{
        for(int i=x+1;i<=maxn[x]&&i<=nx;i++){
            dfs(i,ymy+1,nx);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(maxn,-1,sizeof(maxn));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            maxn[i]=-1;
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    maxn[i]=j;
                }
            }
        }

        for(int i=1;i<n;i++){
            if(maxn[i]==-1){
                continue;
            }

            for(int j=maxn[i]+1;j<=n;j++){
                maxi=0;
                for(int k=i;k<j;){
                    k=maxn[k];
                    maxi+=1;
                }
                cnt=0;
                dfs(i,0,j);
                if(cnt==2){
                    ans+=1;
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
