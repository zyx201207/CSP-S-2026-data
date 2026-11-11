#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000010;
int n; ll d,a[N];
int nxt[N];
ll f[N][6];
/*
the following state exists:
1 X     0
1 G     1
1 1 X   2
1 1 G   3
2 X     4
2 G     5
X       -1
G       -1
*/
int st[6][3]={
{1,0,0},
{1,2,0},
{1,1,0},
{1,1,1},
{2,0,0},
{2,1,0},
};
int trans(int id,int a[3],int &c){
    int tot[4]={0,0,0,0};
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=st[id][i];
        tot[sum]+=a[i];
    }
    // putchar('[');
    // for(int i=1;i<=3;i++) printf("%d ",tot[i]);
    // putchar(']');
    c=tot[2];
    if(tot[1]==0){
        if(tot[2]==0) return -1;
        else if(tot[2]==1){
            if(tot[3]==0) return 4;
            else return 5;
        }else return 5;
    }else if(tot[1]==1){
        if(tot[2]==0&&tot[3]==0) return 0;
        else return 1;
    }else if(tot[1]==2){
        if(tot[2]==0&&tot[3]==0) return 2;
        else return 3;
    }else return 3;
}
void work(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&a[j]-a[i]<=d) j++;
        nxt[i]=j-1;
    }
    // for(int i=1;i<=n;i++) printf("%d ",nxt[i]); putchar('\n');
    for(int i=0;i<=n;i++)
        for(int j=0;j<6;j++)
            f[i][j]=0;
    ll ans=0;
    // ll tot[20]; memset(tot,0,sizeof(tot));
    for(int i=1;i<=n;i++){
        f[i][0]++;
        int a=nxt[i],b=(i>1?max(i,nxt[i-1]):i),c=(i>2?max(i,nxt[i-2]):i);
        int lis[3]={a-b,b-c,c-i};
        // printf("(%d,%d,%d) ",lis[0],lis[1],lis[2]);
        for(int j=0;j<6;j++){
            // printf("%lld ",f[i][j]);
            int add,to=trans(j,lis,add);
            // printf("%d %d -> %d %d\n",i,j,nxt[i],to);
            ans+=f[i][j]*add;
            // tot[i]+=f[i][j]*add;
            if(to==-1) continue;
            f[nxt[i]][to]+=f[i][j];
        }
        // printf("ans=%lld\n",ans);
    }
    // for(int i=1;i<=n;i++)
    //     printf("%lld ",tot[i]); putchar('\n');
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t; scanf("%d%d",&c,&t);
    while(t--) work();
    return 0;
}