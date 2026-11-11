#include<bits/stdc++.h>
using namespace std;
long long a[200000+10];
long long n,m,ans=-1000000000;
void dfs(long long cnt,long long start,long long x){
    //cout<<a[start]<<' '<<x<<endl;
    if(start>n)return;
    if(cnt==m){
        ans=max(ans,x&a[start]);
        //cout<<start<<endl;
        return;
    }

    if(n-start<m-cnt)return;
    //cout<<start<<endl;
    for(int i=start+1;i<=n-m+cnt+1;i++){
        dfs(cnt+1,i,x&a[i]);

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        long long aaa=a[1];
        for(long long i=1;i<=n;i++){
            aaa&=a[i];
        }
        cout<<aaa;
        return 0;
    }
    if(m==n-1){
        long long t=-100000000;
        for(long long i=1;i<=n;i++){
                long long y=a[1];
                if(i==1)y=a[2];
            for(long long j=1;j<=n;j++){
                if(i==j)continue;
                y&=a[i];

            }
            t=max(t,y);
        }
        cout<<t;
        return 0;
    }
    for(long long i=1;i<=n-m;i++){
        dfs(1,i+1,a[i]);
     //   cout<<-1<<endl;
    }
    cout<<ans;

    return 0;
}
