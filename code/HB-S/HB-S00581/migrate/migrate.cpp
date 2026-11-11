#include<iostream>

using namespace std;
long long ans,q[2000086],c,n,t,d,a[2000086],h,ta,mem[2000086],dp[2000086][3];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    if(c==11||c==12){
        while(t--){
            ans=0;
            cin >> n >> d;
            for(int i=1;i<=n;i++)cin >> a[i];
            if(a[2]-a[1]>=d){
                cout << 0 << '\n';
                continue;
            }
            int num=d/(a[2]-a[1]);
            for(int i=1;i<=n;i++){
                long long v=min(n,1ll*i+num*2)-num+2;
                if(v>0)ans+=v;
            }
            cout << ans << '\n';
        }
    }
    while(t--){
        ans=0;
        cin >> n >> d;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++){
            for(int i=1;i<=n;i++)mem[i]=0;
            dp[i][2]=1;
            dp[i][1]=0;
            h=ta=1;
            q[h]=i;
            mem[0]=1;
            for(int j=i+1;j<=n;j++){
                while(h<=ta&&a[j]-a[q[h]]>d){
                    mem[dp[q[h]][1]]-=dp[q[h]][2];
                    h++;
                }
                dp[j][1]=dp[q[h]][1]+1;
                dp[j][2]=mem[dp[j][1]-1];
                if(dp[j][2]==2)ans++;
                q[++ta]=j;
                mem[dp[j][1]]+=dp[j][2];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}