#include<cstdio>
#include<algorithm>
using namespace std;

long long a[500005];

bool f1(long long z,long long l){
    return z<l;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,f1);
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        long long op=0;
        long long num=1;
        for(int k=i-1;k>=1;k--){
            op+=a[i]-a[k];
            num++;
            if(op==m){
                if(num>maxn){
                    maxn=num;
                }
            }
            else if(op>m){
                num--;
                if(num>maxn){
                    maxn=num;
                }
                break;
            }
            else if(k==1){
                if(num>maxn){
                    maxn=num;
                }
            }
        }
    }
    printf("%lld",maxn);
    return 0;
}
