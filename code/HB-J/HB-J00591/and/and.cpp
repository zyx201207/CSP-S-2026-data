#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=-0x3f3f3f3f;
long long a[200005];
long long box[200005];
void dfs(long long x,long long step){
    if(x>m){
        return;
    }
    if(step==n+1&&x==m){
        long long sum=box[1];
        for(long long i=1;i<=m;i++){
            sum&=box[i];
        }
        mx=max(mx,sum);
        return;
    }
    if(step==n+1){
        return;
    }
    box[x]=a[step];
    dfs(x,step+1);

    dfs(x+1,step+1);


}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1||n>2000){
        for(long long i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }
    else if(m==2){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                if(i!=j){
                    long long x=a[i]&a[j];
                    mx=max(mx,x);
                }

            }
        }
        cout<<mx;
    }
    else if(m==n){
        long long sum=a[1];
        for(long long i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
    }
    else if(m==n-1){
        long long sum=a[1];
        for(long long i=1;i<=n;i++){
            sum&=a[i];
        }
        for(long long i=1;i<=n;i++){
            mx=max(mx,sum&a[i]);
        }
        cout<<mx;
    }
    else{
        dfs(1,1);
        cout<<mx;
    }

    return 0;
}
