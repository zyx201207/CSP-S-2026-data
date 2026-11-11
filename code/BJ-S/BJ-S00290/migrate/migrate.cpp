#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,cnt[N],dis[N];
long long d,a[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            if(n==1){
                cout<<0<<endl;
            }else{
                int sum=d/(a[2]-a[1]);
                if(sum<=1)cout<<0<<endl;
                else cout<<max(0,n-2*sum+1)<<endl;
            }
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        int last=n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=last;j++)dis[j]=1e9,cnt[j]=0;
            dis[i]=0;cnt[i]=1;
            last=i;
            int key=i;
            for(int j=i+1;j<=n;j++){
                while(a[j]-a[last]>d)last++;
                if(last==j)break;
                dis[j]=dis[last]+1;
                while(dis[key+1]==dis[last])key++;
                if(key-last+1>=3)cnt[j]=3;
                else{
                    cnt[j]=cnt[last];
                    if(key-last+1==2)cnt[j]=min(3,cnt[j]+cnt[last+1]);
                }
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
