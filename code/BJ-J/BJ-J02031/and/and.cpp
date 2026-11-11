#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m1[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
ll a[200010],ax[200010][35];
vector<ll> d[35],an;

void fx(int x){
    int tg=0;
    while(x){
        tg++;
        if(x&1) d[tg].push_back(x);
        x=x>>1;
    }
}

void fx1(int x){
    int tg=0;
    int x1=a[x];
    while(x1){
        tg++;
        if(x1&1) ax[x][tg]=1;
        x1=x1>>1;
    }
}

int main (){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        fx(a[i]);
        fx1(i);
    }
    int x;
    for(int i=30;i>=1;i--){
        if(d[i].size()>=m){
            an.push_back(i);
            x=i;
        }
    }
    if(an.size()==0){
        printf("0");
        return 0;
    }
    if(an.size()==1){
        printf("%lld",m1[x-1]);
        return 0;
    }
//     ll ans=m1[an[0]];
//     for(int i=0;i<d[an[0]].size();i++){
//         int num=0;
//         for(int j=1;j<=35;j++){
//             if(ax[d[an[i]]][j]==1){
//                 ans+=m1[j];
//             }
//         }
//     }
//    printf("%lld",ans);
    return 0;
}