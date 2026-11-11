#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
long long c,T,n,d,dis[303][303],dp[303][303],a[N],L[N],R[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c>=11&&c<=12){
            int x=1;
            if(a[n]-a[1]<=d){
                cout<<0<<endl;
                continue;
            }
            while(a[x]-a[1]<=d)x++;
            if(x<=3){
                cout<<0<<endl;
                continue;
            }
            cout<<n-2*(x-2)+1<<endl;
            //cout<<n<<" "<<x<<endl;
            continue;
        }
        if(c>=13&&c<=14){
            long long l=1,r=0,ans=0;
            for(int i=1;i<=n;i++)R[i]=1e9,L[i]=0;
            for(;l<=n;l++){
                while(r<=n-1&&a[r+1]-a[l]<=d){
                    r++;
                    R[r]=min(R[r],l);
                }
                L[l]=r;
            }
            int x=1,y=n;
            if(a[n]-a[1]<=d){
                cout<<0<<endl;
                continue;
            }
            while(a[x]-a[1]<=d)x++;
            while(a[n]-a[y]<=d)y--;
            int cnt=x-y-1;
            if(cnt==2){
                long long ans=0;
                for(int i=1;i<=y;i++){
                    if(L[i]<x){
                            ans+=n-L[y];
                            //cout<<"@"<<i<<" "<<n-L[y]<<endl;
                            }

                }
                /*
                for(int i=x;i<=n;i++){
                    if(R[i]>y)ans+=R[x]-1;
                }
                */
                cout<<ans<<endl;
            }else if(cnt>=3){
                cout<<0<<endl;
            }else{


                //for(int i=1;i<=n;i++)cout<<L[i]<<" "<<R[i]<<endl;
                //continue;
                /*
                long long sum=0,ans=0;
                for(int i=y;i>=1;i--){
                    sum+=R[i];
                    ans+=sum-R[i]*(y-i+1);
                }

                sum=0;
                for(int i=x;i<=n;i++){
                    sum+=L[i];
                    ans+=L[i]*(i-x+1)-sum;
                }
                */
                if(y>=2)ans+=(L[y]-L[y-1])*(y-1);
                //cout<<ans<<endl;
                if(x<=n-1)ans+=(R[x+1]-R[x])*(n-x);
                cout<<ans<<endl;

            }
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=1e9;
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    dis[i][j]=dis[j][i]=dp[i][j]=dp[j][i]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int x=1;x<=n;x++){
                for(int y=1;y<=n;y++){
                    if(dis[x][y]>dis[x][k]+dis[k][y]){
                        dis[x][y]=dis[x][k]+dis[k][y];
                        dp[x][y]=dp[x][k]*dp[k][y];
                    }else if(dis[x][y]==dis[x][k]+dis[k][y]){
                        dp[x][y]+=dp[x][k]*dp[k][y];
                    }
                }
            }
        }
        long long cnt=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt+=(dp[i][j]==2);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }

        cout<<cnt/2<<endl;
    }
    return 0;
}
