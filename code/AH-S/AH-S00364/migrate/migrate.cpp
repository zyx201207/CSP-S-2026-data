//OI太难了我去学物理竞赛了拜拜
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int C,T,n,d;
int a[N],f[N],lst[N],num[N],sum[N];
int sl[N],sr[N];
void solve(){
    int ans=0;
    if(a[n]-a[1]<=d){
        cout<<0<<endl;
        return ;
    }
    for(int i=1,l=1;i<=n;i++){
        while(l<=n&&a[l]-a[i]<=d)l++;
        sr[i]=l-1;
    }
    for(int i=n,l=n;i>=1;i--){
        while(l>=1&&a[i]-a[l]<=d)l--;
        sl[i]=l+1;
    }
    for(int i=1,l=1;i<=n;i++){
        while(l<=n&&sl[l]-sr[i]<-1)l++;
        while(l<=n&&sl[l]-sr[i]==-1){
            ans++;
            l++;
        }
        l--;
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(C==13||C==14){
            solve();
        }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)sum[j]=0,f[j]=0,lst[j]=0,num[j]=sum[j]=0;
            lst[0]=i;
            num[i]=sum[i]=1;
            for(int j=i+1,l=i;j<=n;j++){
                while(l<j&&a[j]-a[l]>d)l++;
                if(l==j)break;
                num[j]=sum[lst[f[l]]]-sum[l-1];
                sum[j]=sum[j-1]+num[j];
                f[j]=f[l]+1;
                lst[f[j]]=j;
                if(num[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;}
    }
    return 0;
}
//Oct31==Dec25?
