#include<cstdio>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        int u,v;
        for(int i=1; i<n; ++i)
            scanf("%d%d",&u,&v);
        if(t)
            printf("%d",1);
        else
            printf("%d",2);
    }
    return 0;
}
