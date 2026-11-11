#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long x[2000100];
int c,t;
int check(){
    return 0;


}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
scanf("%d %d",&c,&t);
while(t>0){
    scanf("%lld %lld",&n,&d);
    for (long long i=0;i<n;i++){
        scanf("%lld",&x[i]);
    }
    int meizhaole=check();
    printf("%d",&meizhaole);
    t--;
}


return 0;
}
