#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int a[N];
int dp[200005],type[200005];
int zvis[N],fvis[N];
queue<pair<int,int> > q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c<=10){
            for(int k=1;k<=n;k++){
                for(int i=k+1;i<=n;i++)dp[i]=0x3f3f3f3f;
                dp[k]=0;
                type[k]=1;
                for(int i=k+1;i<=n;i++){
                    for(int j=i-1;j>=k&&a[i]-a[j]<=d;j--){
                        if(dp[j]+1<dp[i])dp[i]=dp[j]+1,type[i]=type[j];
                        else if(dp[j]+1==dp[i])type[i]+=type[j];
                    }
                    if(type[i]==2)ans++;
                }
            }
        }else if(c==11||c==12){
            int num=0;
            for(int i=1;i<=n;i++){
                if(a[1]+d>=a[i])num=i;
            }
            num--;
            if(n==2*num)ans=1;
            else ans=0;
        }else{
            for(int i=1;i<=n;i++)zvis[i]=fvis[i]=0;
            for(int i=1;i<=n;i++){
                int l=i+2,r=n,ans=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(a[mid]<=a[i]+d){
                        ans=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                if(ans!=-1){
                    l=ans+1,r=n;int anss=-1;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(a[mid]>a[ans-2]+d){
                            anss=mid;
                            r=mid-1;
                        }else{
                            l=mid+1;
                        }
                    }
                    if(a[anss]-a[ans-1]<=d&&anss!=-1){
                        q.push({i,anss});
                        zvis[i]=fvis[anss]=1;
                    }
                }
            }
            while(!q.empty()){
                int k=q.front().first,j=q.front().second;
                q.pop();
                int numz=1;
                for(k=k-1;k>=1;k--)if(zvis[k]==0&&a[k+1]-a[k]<=d)numz++;else break;
                ans+=numz;
                for(j=j+1;j<=n;j++)if(fvis[j]==0&&a[j]-a[j-1]<=d)ans+=numz;else break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}