#include<cstdio>
using namespace std;
long long int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        long long int d;
        scanf("%d%lld",&n,&d);
        for(int i=1; i<=n; ++i){
            scanf("%d",&x[i]);
        }
        long long int gc=x[2]-x[1];
        int i=0;
        while((i+1)*gc<=d)
            ++i;

        printf("0\n");
    }
    return 0;
}
