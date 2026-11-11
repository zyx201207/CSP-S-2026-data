#include<cstdio>
#include<cstring>
using namespace std;

int b[2000005];
int n,d;

struct aaa{
    int num;
    int minn;
};

aaa a[305][305];
int c2[5005];
int num=0;

void check(int i,int k,int cnt,int start,int goal){
    if(i==k){
        if(cnt<a[start][goal].minn){
            a[i][k].num=1;
            a[i][k].minn=cnt;
            return;
        }
        else if(cnt==a[start][goal].minn){
            a[i][k].num++;
            return;
        }
    }
    for(int p=i;i<=k;p++){
        if(a[p]-a[i]<='d'){
            c2[++num]=p;
        }
    }
    for(int p=1;p<=num;p++){
        check(c2[p],k,cnt+1,start,goal);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for(int l=1;l<=t;l++){
        for(int i=0;i<=302;i++){
            for(int k=0;k<=302;k++){
                a[i][k].minn=2e8;
            }
        }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        if(b[1]+d>=b[n]){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(i>=k||b[i]+d>=b[k]){
                    continue;
                }
                else{
                    memset(c2,0,sizeof(c2));
                    num=0;
                    check(i,k,0,i,k);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(i==k||i>k){
                    continue;
                }
                else{
                    if(a[i][k].num==2){
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
