#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],mx=-0x3f3f3f3f3f3f3f3f;
long long sum;
bool b[200005];
void dfs(int m,long long sum){
    if(m==0){
        mx=max(mx,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            long long cnt=sum;
            sum=(sum&a[i]);
            b[i]=1;
            dfs(m-1,sum);
            b[i]=0;
            sum=cnt;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }else if(m==n){
        long long pos=a[1];
        for(int i=2;i<=n;i++){
            pos=(pos&a[i]);
        }
        cout<<pos;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout<<mx;
    }else if(n<=20&&m<=n){
        for(int i=1;i<=n;i++){
            memset(b,0,sizeof(b));
            b[i]=1;
            dfs(m-1,a[i]);
        }
        cout<<mx;
    }else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
