#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500005];
long long o;
long long t[505][200005],w[505][200005];
long long sumz[100005];
int in=1;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&o);
        for(int j=1;j<=o;j++){
            scanf("%lld%lld",&w[i][j],&t[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        long long x,y;
        scanf("%lld%lld",&x,&y);
        long long sum=0;
        if(x==y-1){
            sum=a[x]+a[y]+t[x][y-1]+t[x][y];
        }else{
            sum=a[x]+a[y]+t[1][1];
            for(int k=1;k<=y/3;k++){
                sum=sum+t[k][k+1]+t[k+1][k+1];

            }

            sum+=t[x+1][y];
        }

        sumz[in]=sum;
        in++;

    }
    for(int i=1;i<=in-1;i++){
        cout<<sumz[i]<<endl;
    }


    return 0;
}
//4 5 7 3 4 9
//4 5 7 O
//Oct31==Dec25?
