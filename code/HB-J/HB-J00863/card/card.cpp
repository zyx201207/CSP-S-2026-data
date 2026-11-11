#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],b[N],c[N];
int sum=0;
int check(int x,int y){
    bool b1=true;
    for(int i=x;i<=y;i++){
        if(a[i]==a[x]){
            for(int j=i+1;j<=sum;j++){
                sum--;
                b[j]=-1;
                b1=false;
            }
        }
    }
    if(b1==true)b[++sum]=a[y];
    return sum;
}
void sumn(int sum){
    for(int i=1;i<=sum;i++){
        if(b[i]==-1)continue;
        c[b[i]]++;
    }
    memset(b,-1,sizeof b);
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(b,-1,sizeof b);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int nf=check(i,j);
        }
        sumn(sum);
        sum=0;
    }
    for(int i=1;i<=m;i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}
