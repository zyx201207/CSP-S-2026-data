#include<bits/stdc++.h>
using namespace std;
int a[200010];long long dis[200010];
char c[200010],cc[100000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long ans=0,su=1,suu=0;
    for(int i=1;i<=n;++i){
        scanf("%d",a+i);
        char r;suu+=a[i];
        r=getchar();
        while(r>'z'||r<'a')r=getchar();
        c[i]=r;
        dis[i]+=su;
        //cout<<dis[i]<<' ';
        su+=a[i];
    }//long long su2=dis[n]+a[n];
    if(suu<=1e8+7){
        int cnt=0,an=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=a[i];++j){
                cc[cnt]=c[i];
                ++cnt;
            }
        }for(int i=1;i<suu/2;++i){
            if(cc[i]!=cc[suu-i+1])++an;
        }cout<<an;
        return 0;
    }
    int from=n;//cout<<su<<' ';
    for(int i=1;dis[i]<=(su*1ll/2ll)&&su-(dis[i]+a[i]-1)+1>dis[i];++i){
        if(su-dis[from]+1>dis[i]+a[i]-1){
            if(c[from]!=c[i])ans+=a[i];
            //su2-=a[i];
        }else if(su-dis[from]+1==dis[i]+a[i]-1){
            if(c[from]!=c[i])ans+=a[i];
            //su2-=a[i];
            --from;
        }else{
            for(;dis[from]-a[from]>su/2;){
                if(c[from]!=c[i])ans+=(1ll*su/2ll-dis[i])-dis[from]+1;
                --from;
                if(su-dis[from]+1>dis[i]+a[i]-1){
                    if(c[from]!=c[i])ans+=a[i];
                    //su2-=a[i];
                    break;
                }else if(su-dis[from]+1==dis[i]+a[i]-1){
                    if(c[from]!=c[i])ans+=a[i];
                    //su2-=a[i];
                    --from;
                    break;
                }
            }
        }//cout<<ans<<' '<<su/2<<'\n';
    }cout<<ans;
    return 0;
}