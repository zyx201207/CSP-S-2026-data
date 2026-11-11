#include <bits/stdc++.h>
using namespace std;

int a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&T);
    while (T--){
        bool speA=(c==11 || c==12);
        int n,d;
        scanf("%d%d",&n,&d);
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if (speA){
            int l=a[2]-a[1];
            if (d<2*l){
                printf("0\n");
            }
            for (int i=2;;i++){
                if (i*l<=d && d<i*l+l){
                    int ans=0;
                    for (){

                    }
                }
            }
        }
    }
    return 0;
}
/*0WA*/
