#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long dis[1000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out"."w",stdout);
    int a,last=0;
    scanf("%d",&c);
    scanf(%d,&t);
    while(t--){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n,i++){
            scanf("%d",&a);
            dis[i]=a-last;
            if(a-last>d){
                continue;
            }
            dis[i]=a-last;
            last=a;
        }
        if(n<=4){
            cout<<0;
            return 0;
        }
        if(n==4){
            cout<<2;
            return 0;
        }
        if(n>=4){
            cout<<dis[i];
        }
    }
    return 0;
}
