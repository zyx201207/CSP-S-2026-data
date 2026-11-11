#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t,n;
ll di,x[N];
int f(int a,int b,int step){
    if(a==b){
        if(step>=0)return 1;
        else return 0;
    }
    if(x[b]-x[a]>step*di)return 0;
    int ans=0;
    for(int i=a+1;i<=b;i++){
        if(x[i]-x[a]>di)break;
        ans+=f(i,b,step-1);
    }
//    cout<<a<<b<<step<<ans<<endl;
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        scanf("%d%d",&n,&di);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        int ans=0;
        for(int i=3;i<n;i++){
            for(int j=1;j<=n-i;j++){
                if(f(j,j+i,(x[j+i]-x[j])/di+1)==2){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
