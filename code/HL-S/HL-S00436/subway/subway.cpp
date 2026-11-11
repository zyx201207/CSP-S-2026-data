#include<bits/stdc++.h>
using namespace std;
int w[500100];
int c,n,m,d,q;//m地铁站
int no1,no2;
//动态规划吓哭了，有点像dijkstra
int a[20][500100];
int x,y;
int mz;
int check(int l,int r){
    pass;

    }

int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
for (int i=1;i<=m;i++){
    scanf("%d",&w[i]);
}
int k=0;
for (int i=0;i<n;i++){
    scanf("%d",&k);
    for (int j=0;j<k;j++){
        scanf("%d %d",&no1,&no2);
        a[i][no1]=no2;
    }
}
for(int i=0;i<q;i++){
    mz=1<<15;
    scanf("%d %d",&x,&y);
    check(x,y);
    printf("%d\n",mz);
}


return 0;

}
