#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=2e5+10;
long long a[N];
long long dp[N];
bool f[25];
long long maa=0;
long long p(){
    long long sum;
    long long p;
    for(long long i=1;i<=n;i++){
        if(f[i]){
            sum=a[i];
            p=i;
            break;
        }
    }
    for(long long i=p+1;i<=n;i++){
        if(f[i]){
            sum&=a[i];
        }
    }
    return sum;
}
void dfs(long long x,long long cnt){
    if(cnt==m){
        maa=max(maa,p());
        return;
    }
    for(long long i=1;i<=n;i++){
        if(!f[i]&&i!=x){
            f[i]=true;
            dfs(i,cnt+1);
            f[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long ma=-1;
        for(long long i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma;
        return 0;
    }else if(m==2){
        long long ma=-1;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ma=max(ma,a[i]&a[j]);
            }
        }
        cout<<ma;
        return 0;
    }else if(m==n){
        long long k=a[1];
        for(long long i=2;i<=n;i++){
            k=a[i]&k;
        }
        cout<<k;
    }else if(n<=25){
        dfs(1,0);
        cout<<maa<<endl;
    }else if(m==n-1){
        long long ma=0;
        for(int i=1;i<=n;i++){
            long long k;
            if(i==1) k=a[2];
            else k=a[1];
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                k&=a[j];
            }
            ma=max(ma,k);
        }
        cout<<ma;
    }else{
        sort(a+1,a+n+1);
        long long cnt=0;
        for(long long i=n;i>=1;i--){
            cnt++;
            if(cnt==m){
                cout<<a[i];
                return 0;
            }
        }
    }
    return 0;
}
