#include<bits/stdc++.h>
#define int long long
using namespace std;
int db;
int c,T,n,d,a[2000005],dp[2000005],as;
signed lt[2000005],rt[2000005];
vector<signed> p;
void init(){
    p.clear();
}
int dfs(int x,int r,int st){
    if(x==r){
        if(st==dp[r])return 1;
        return 0;
    }
    int sum=0;
    for(int j=x+1;j<=r;j++){
        sum+=dfs(j,r,st+1);
    }
    return sum;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    db=0;
    if(db==0){
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
    }
    cin>>c>>T;
    if(c<=6){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int ans=0;
            for(int l=1;l<=n;l++){
                for(int r=l+1;r<=n;r++){
                    for(int i=l+1;i<=r;i++)dp[i]=1e9;
                    dp[l]=0;
                    for(int i=l;i<=r;i++){
                        for(int j=i+1;j<=r;j++){
                            if(a[j]-a[i]<=d)dp[j]=min(dp[j],dp[i]+1);
                        }
                    }
                    as=0;
                    if(dfs(l,r,0)==2)ans++;
                }
            }
            cout<<ans<<endl;
        }
    }else{
        while(T--){//duo ce qing kong
            init();
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int l=1,r=1;
            for(int i=1;i<=n;i++){
                while(a[i]-a[l]>d)l++;
                while(r<n&&a[r+1]-a[i]<=d)r++;
                lt[i]=l;
                rt[i]=r;
            }
            p.push_back(0);
            for(int i=2;i<n-1;i++){
                if((i==rt[i-1]||rt[i-1]<=i+1) && (i==lt[i+2]||lt[i+2]<=i+1)){
                    p.push_back(i);
                }
            }
            p.push_back(n);
            int ans=0;
            for(int i=1;i<p.size()-1;i++){
                // if(db&&T==0)cout<<p[i]<<' '<<max(p[i-1]+1,lt[p[i]+1])<<' '<<min(p[i+1],rt[p[i]])<<endl;
                ans+=max(0,(p[i]-max(p[i-1],lt[p[i]+1]))*(min(p[i+1]+1,rt[p[i]])-p[i]-1));
            }
            cout<<ans<<endl;
        }   
    }

    return 0;
}