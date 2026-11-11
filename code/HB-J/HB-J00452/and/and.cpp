#include<cstdio>
using namespace std;

long long a[200005];
long long maxn=-2e8;
int n,m;

void f(int i,int cnt,long long num){
    if(cnt==m){
        if(num>maxn){
            maxn=num;
        }
        return;
    }
    if(i>n){
        return;
    }
    else{
        if(num==-1){
            f(i+1,cnt+1,a[i]);
            f(i+1,cnt,num);
        }
        else{
            f(i+1,cnt+1,num&a[i]);
            f(i+1,cnt,num);
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    f(1,0,-1);
    printf("%lld",maxn);
    return 0;
}
