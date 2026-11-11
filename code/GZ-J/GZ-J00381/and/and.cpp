//GZ-J00381 º«ÓúÐÅ
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005],vis[200005];
int cnt,power[32];
int ans,last=1;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int tmp=a[i],num;
        while(tmp){
            tmp/=2;
        }
    }

    sort(a+1,a+1+n);
    power[0]=1;
    for(int i=1;i<=31;i++){
        power[i]=power[i-1]*2;
    }

    for(int i=30;i>=0;i--){
        int cnt=0;
        int l=last;
        for(int j=n;j>=1;j--){
            if(vis[j]) continue;
            if(a[j]%power[i+1]/power[i]==0) {vis[j]=i;}
            else cnt++;
        }
        if(cnt<m) {
                ans*=2;
            for(int j=1;j<=n;j++) vis[j]=(vis[j]==i?0:vis[j]);
        }
        else{
            ans=ans*2+1;
        }
    }
    cout<<ans;
    return 0;
}
