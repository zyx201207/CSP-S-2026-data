#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d;
long long a[N];
long long cha;
int main(){
    //我的梦想是北航，去给国家做卫星，火箭，战斗机
    //thats what i want to
    //i want something just like this
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(n==1){
            printf("0\n");
            continue;
        }
        int bei=0;
        cha=a[2]-a[1];
        for(int i=1;i<=n;i++){
            if(i*cha>d){
                bei=i-1;
                break;
            }
        }
        if(bei==0){
            printf("0\n");
            continue;
        }
        long long sum=0;
        for(int i=1;i<=n-bei-1;i++){
            int ans=n-i;
            ans-=bei;
            int ans1=ans-ans/(bei+1);
            sum+=ans1;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
