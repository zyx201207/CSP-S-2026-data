#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int ans;
int dfs(int i,int cnt,int sum,int f){
    //cout<<i<<":"<<cnt<<" "<<sum<<" "<<f<<endl;
    if(cnt==m) return sum;
    if(i==n){
       // cout<<"%%"<<sum<<endl;
        return 0;
    }
    int t=n-i+1;
    int t2=m-cnt;
    if(t2>t) return 0;
    int x=0,y=0;
    if(cnt<m){
       // cout<<a[i+1]<<endl;
        if(f==1) x=dfs(i+1,cnt+1,a[i+1],0);
        else x=dfs(i+1,cnt+1,(sum&a[i+1]),0);
    }
    if(f==1) y=dfs(i+1,cnt,sum,1);
    else y=dfs(i+1,cnt,sum,0);

    return max(x,y);

}
signed main(){//&->按为与
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000||m>5000){
        if(m==n-1){
            int ans=0,cnt=0;
            for(int i=1;i<=n;i++){
                int f=1;
                cnt=0;
                for(int j=1;j<=n;j++){
                    if(j==i) continue;
                    if(f==1){
                        f=0;
                        cnt=a[i];
                    }else{
                        cnt&=a[i];
                    }

                }
                ans=max(ans,cnt);
            }
            cout<<ans;
        }
        return 0;
    }
    cout<<dfs(0,0,0,1);

   return 0;
}//dp???!
