#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n=0,ans=0,cnt=0;
long long m=0;
bool vis[N];
int a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long t=m;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            break;
        }
        vis[i]=1;
        for(int j=1;j<=n;j++){
            b[j]=a[i]-a[j];
        }
        ans=0;
        t=m;
        for(int j=1;j<=n;j++){
            if(t>=b[j]&&b[j]>=0){
                t=t-b[j];
                ans++;
            }
        }
        cnt=max(cnt,ans);
    }
    printf("%d",cnt);
    return 0;
}
