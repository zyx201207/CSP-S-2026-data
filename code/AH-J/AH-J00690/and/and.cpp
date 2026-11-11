#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e3+5;
LL a[N],d[N][N],n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(m==1||m==n){
        LL ma=0,sum=0,x;
        cin>>x;
        ma=x;
        sum=x;
        for(LL i=2;i<=n;i++){
            cin>>x;
            ma=max(ma,x);
            sum=sum&x;
        }
        if(m==1) cout<<ma;
        else cout<<sum;
    }
    else if(m==2){
        LL b[200010];
        for(LL i=1;i<=n;i++) cin>>b[i];
        LL M=0;
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++) M=max(M,b[i]&b[j]);
        }
        cout<<M;
    }
    else{
        for(LL i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            d[i][1]=a[i];
        }
        for(LL i=1;i<=n;i++){
            for(LL j=1;j<=min(i,m);j++){
                for(LL k=i-(i-j)-1;k<i;k++){
                    d[i][j]=max(d[i][j],a[i]&d[k][j-1]);
                }
            }
        }
        LL maxn=0;
        for(LL i=n-m;i<=n;i++) maxn=max(maxn,d[i][m]);
        cout<<maxn;
    }
    return 0;
}
