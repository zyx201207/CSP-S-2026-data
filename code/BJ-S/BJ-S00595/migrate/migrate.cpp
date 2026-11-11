#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,a[2000005];
int x[2000005];
void read(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    return ;
}
void solve(){
    for(int i=1;i<=n;i++){
        x[i]=0;
        for(int j=i+1;j<=n;j++){
            if(a[j]-a[i]>d){
                x[i]=j-1;
                break;
            }
            if(j==n&&a[j]-a[i]<=d) x[i]=n;
        }
        if(x[i]==0) x[i]=i;
    }
    int tt=0,flag=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+3;j<=n;j++){
            tt=i;
            flag=1;
            while(x[tt]<j&&flag<=2){
                if(x[tt]==tt){
                    flag=0;
                    break;
                }
                if(x[tt]-1>tt&&min(x[x[tt]-1],j)==min(x[x[tt]],j)){
                    flag++;
                }
                if(x[tt]-2>tt&&min(x[x[tt]-2],j)==min(x[x[tt]],j)){
                    flag++;
                }
                tt=x[tt];
            }
            if(flag==2){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return ;
}
void solvea(){
    x[1]=0;
    for(int j=2;j<=n;j++){
        if(a[j]-a[1]>d){
            x[1]=j-1;
            break;
        }
        if(j==n&&a[j]-a[1]<=d) x[1]=n;
    }
    if(x[1]==0||x[1]==1||x[1]*2+1>n){
        printf("0\n");
        return ;
    }
    if((a[x[1]]-a[1])%d!=0){
        printf("%d\n",n-x[1]*2+1);
    }
    else{
        printf("%d\n",n-(x[1]-1)*2+1);
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        read();
        if(c==11||c==12){
            solvea();
        }
        else{
            solve();
        }
    }
    return 0;
}