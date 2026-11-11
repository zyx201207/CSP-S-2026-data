#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],k[N][505],t[N][505],a[N][25],p1[N],p2[N],cnt1=0,cnt2=0;
bool check(int x,int y){
    if(x>y)swap(x,y);
    if(x==y)return true;
    for(int i=1;i<=a[x][0];i++){
        for(int j=1;j<=k[i][0];j++){
            if(k[i][j]==x)p2[++cnt2]=j;
            if(k[i][j]==y){p1[++cnt1]=i,p2[++cnt2]=j;return true;}
        }
    }
    return false;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i][0]);
        for(int j=1;j<=k[i][0];j++){
            scanf("%d%d",&k[i][j],&t[i][j]);
            a[k[i][j]][i]=1;
            a[k[i][j]][0]++;
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int tim=w[x]+w[y];
            cnt1=cnt2=0;
        if(check(x,y)){tim+=t[p1[1]][p2[1]]+t[p1[1]][p2[2]];}
        else for(int i=1;i<=m;i++){
            cnt1=cnt2=0;
            if(check(x,i)&&check(i,y)){
            tim+=t[p1[1]][p2[1]]+t[p1[1]][p2[2]]+t[p1[2]][p2[3]]+t[p1[2]][p2[4]];break;}
        }
        if(tim==w[x]+w[y]){
            for(int i=1;i<=m;i++){
                    for(int j=1;j<=m;j++){
                        cnt1=cnt2=0;
                        if(x!=i&&i!=j&&j!=y&&check(x,i)&&check(i,j)&&check(j,y)){
                        tim+=t[p1[1]][p2[1]]+t[p1[1]][p2[2]]+t[p1[2]][p2[3]]+t[p1[2]][p2[4]]+t[p1[3]][p2[5]]+t[p1[3]][p2[6]];break;}
                    }

            }
        }
        printf("%d\n",tim);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
