#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[200005];
int mc[32];
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i ++) {
        scanf("%d",&a[i]);
        for(int j = 0;j < 32;j ++) mc[j]+=(a[i]>>j)&1;
    }
    //for(int i = 0;i < 32;i ++) printf("[%d",mc[i]);
    //sort(a,a+n);
    int ans1=0;
    int tm=m;
    for(int i = 31;i >= 0;i --) {
        //printf("[%d] %d\n",i,mc[i]);
        if (i==0) {
            //for(int i = 0;i < 32;i ++) printf("[%d",mc[i]);
            //puts("");
        }
        if (mc[i]>=m) {
            ans1|=(1<<i);
            memset(mc,0,sizeof(mc));
            for(int k = 0;k < n;k ++) {
                if ((a[k]&ans1)==ans1) {
                    for(int j = 0;j < 32;j ++) mc[j]+=(a[k]>>j)&1;
                }
            }
        }
        //printf("ans:%d\n",ans1);
    }
    printf("%d\n",ans1);
}
