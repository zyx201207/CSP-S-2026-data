#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++) scanf("%d%d",&u,&v);
        printf("%d\n",n/2-k);
    }
    return 0;
}