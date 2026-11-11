#include<bits/stdc++.h>
using namespace std;
int a[200010];long long dis[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    long long ans=0,su=1;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        char r;
        r=getchar();
        while(r>'z'||r<'a')r=getchar();
        c[i]=r;
        dis[i]+=su;
        //cout<<dis[i]<<' ';
        su+=a[i];
    }long long su2=dis[n]+a[n];
    int from=n;//cout<<su<<' ';
    for(int i=1;dis[i]<=(su/2)&&su-(dis[i]+a[i])+1>dis[i];++i){
        if(su-dis[from]+1>dis[i]){
            if(c[from]!=c[i])ans+=a[i];
            su2-=a[i];
        }else if(su-dis[from]+1==dis[i]){
            if(c[from]!=c[i])ans+=a[i];
            su2-=a[i];
            --from;
        }else{
            for(;dis[from]+a[i]>su/2;){
                if(c[from]!=c[i])ans+=(su/2-dis[i])-dis[from]+1;
                --from;
                if(su-dis[from]+1>dis[i]){
                    if(c[from]!=c[i])ans+=a[i];
                    su2-=a[i];
                    break;
                }else if(su-dis[from]+1==dis[i]){
                    if(c[from]!=c[i])ans+=a[i];
                    su2-=a[i];
                    --from;
                    break;
                }
            }
        }//cout<<ans<<' '<<su/2<<'\n';
    }cout<<ans;
    return 0;
}