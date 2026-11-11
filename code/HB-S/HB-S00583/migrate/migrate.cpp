#include<bits/stdc++.h>
using namespace std;
const int N=20;
int c,t,a[N],b[N],st,n,d,ans,s[15];
void dfs(int x,int y){
    if(x==y+1){
        int res=0,cnt=0;
        for(int i=st+1;i<=y;i++){
            if(i==y&&b[i]==0) return;
            res+=a[i]-a[i-1];
            if(b[i]){
                if(res>d) return;
                res=0;cnt++;
            }
        }
        s[cnt]++;
        return;
    }
    b[x]=1;
    dfs(x+1,y);
    b[x]=0;
    b[x]=0;
    dfs(x+1,y);
    b[x]=0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(j-i+1<=3) continue;
                st=i;
                memset(s,0,sizeof(s));
                dfs(i+1,j);
                for(int k=1;k<=20;k++){
                    if(s[k]){
                        if(s[k]==2){
                            ans++;
                        }
                        else break;
                    }
                }

            }
        }
        cout<<ans<<endl;
    }

    return 0;
}