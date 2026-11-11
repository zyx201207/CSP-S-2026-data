#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mp[5],maxx=0;
long long ansx=0;
void dfs(long long num,long long sum,long long cnt){
    if(num==m){
        ansx=max(ansx,sum);
        return;
    }
    if(cnt==n+1)return;
    dfs(num+1,(sum==-1?a[cnt]:(sum&a[cnt])),cnt+1);
    dfs(num,sum,cnt+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==2&&n<=2000){
        long long ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }
    else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
    else if(n<=20){
        dfs(0,-1,1);
        cout<<ansx;
    }
    else if(maxx<=4){
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
        }
        if(mp[3]>=m){
            cout<<2;
        }
        else if(mp[3]+mp[2]>=m||mp[3]+mp[1]>=m||mp[4]>=m){
            cout<<1;
        }
        else cout<<0;
    }
    else {
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
    return 0;
}