#include<bits/stdc++.h>
using namespace std;
#define int long long
int fw,t,a,b,c[1000005],d[1000005],p[5005][5005],ge[5005][5005],tp[100005][25];
int met(int x,int y){
    if(tp[x][20]!=tp[y][20])return -1;
    for(int i=20;i>=0;i--){
        if(tp[x][i]!=tp[y][i]){
            x=tp[x][i];
            y=tp[y][i];
        }
    }
    if(tp[x][0]==0)return -1;
    return tp[x][0];
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld %lld",&fw,&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        for(int i=1;i<=a;i++){
            scanf("%lld",&d[i]);
        }
        for(int i=1;i<=a;i++){
            c[i]=c[i-1];
            while(1){
                if(c[i]==a)break;
                if(d[c[i]+1]-d[i]<=b){
                    c[i]++;
                }else{
                    break;
                }
            }
        }
        if(fw>=1&&fw<=10){
            int ans=0;
            for(int i=a;i>=1;i--){
                for(int j=1;j<=a;j++){
                    p[i][j]=1e9;
                    ge[i][j]=0;
                }
                if(c[i]>i){
                    for(int j=c[i];j<=a;j++){
                        if(p[c[i]][j]+1<p[i][j]){
                            p[i][j]=p[c[i]][j]+1;
                            ge[i][j]=ge[c[i]][j];
                        }else{
                            if(p[c[i]][j]+1==p[i][j]){
                                ge[i][j]+=ge[c[i]][j];
                                if(ge[i][j]>3)ge[i][j]=3;
                            }
                        }
                    }
                }
                if(c[i]-1>i){
                    for(int j=c[i]-1;j<=a;j++){
                        if(p[c[i]-1][j]+1<p[i][j]){
                            p[i][j]=p[c[i]-1][j]+1;
                            ge[i][j]=ge[c[i]-1][j];
                        }else{
                            if(p[c[i]-1][j]+1==p[i][j]){
                                ge[i][j]+=ge[c[i]-1][j];
                                if(ge[i][j]>3)ge[i][j]=3;
                            }
                        }
                    }
                }
                if(c[i]-2>i){
                    for(int j=c[i]-2;j<=a;j++){
                        if(p[c[i]-2][j]+1<p[i][j]){
                            p[i][j]=p[c[i]-2][j]+1;
                            ge[i][j]=ge[c[i]-2][j];
                        }else{
                            if(p[c[i]-2][j]+1==p[i][j]){
                                ge[i][j]+=ge[c[i]-2][j];
                                if(ge[i][j]>3)ge[i][j]=3;
                            }
                        }
                    }
                }
                for(int j=i+1;j<=c[i]-3;j++){
                    p[i][j]=1;
                    ge[i][j]=1;
                }
                p[i][i]=0;
                ge[i][i]=1;
                for(int j=1;j<=a;j++){
                    if(ge[i][j]==2)ans++;
                }
            }
            printf("%lld\n",ans);
        }
        if(fw==11||fw==12){
            if(c[1]==a||c[1]==1||c[1]==2){
                printf("0\n");
            }else{
                int p=c[1]-1,q;
                q=2*p-1;
                printf("%lld\n",max(0ll,a-q));
            }
        }
        if(fw>=13&&fw<=14){
            int ans=0;
            for(int i=1;i<=a;i++){
                if(c[i]==i)continue;
                if(c[i]==i+1){
                    ans+=(c[c[i]-1]-c[i]);
                    continue;
                }
                ans+=(c[c[i]-1]-max(c[i],c[c[i]-2]));
            }
            printf("%lld\n",ans);
        }
        if(fw>14||fw==0){
            for(int i=1;i<=a;i++){
                if(c[i]==i)c[i]=0;
                tp[i][0]=c[i];
                //printf("%lld ",c[i]);
            }
            //printf("\n");
            for(int j=1;j<=20;j++){
                for(int i=1;i<=a;i++){
                    tp[i][j]=tp[tp[i][j-1]][j-1];
                }
            }
            int ans=0,la=0;
            for(int i=a;i>=1;i--){
                if(c[i]==0)continue;
                if(c[i]==i+1){
                    ans+=la;
                    continue;
                }
                int q1=met(c[i]-1,c[i]),q2=met(c[i]-2,c[i]);
                if(q1==-1){
                    la=0;
                    continue;
                }
                if(c[i]==i+2)q2=a+1;
                //printf("%lld %lld\n",q1,q2);
                la=max(0ll,q2-q1);
                ans+=la;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
