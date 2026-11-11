#include <bits/stdc++.h>
using namespace std;
bool f=1;
int n,m,a[500005],now[500005],c,lst[300005],ans[300005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i-1]>a[i])
            f=0;
    }
    if(f) {
        for(int i=1;i<=n;i++)
            lst[a[i]]=i;
        for(int i=1;i<=m;i++)
            ans[i]=lst[i];
    }
    else {
        for(int k=1;k<=n;k++) {
            c=0;
            // printf("debug %d:\n",k);
            for(int i=1;i<=m;i++)
                lst[i]=0x3f3f3f3f;
            for(int i=k;i<=n;i++) {
                if(lst[a[i]]>c) {
                    now[++c]=a[i];
                    lst[a[i]]=c;
                }
                else
                    c=lst[a[i]];
                // printf("add:%d\n",a[i]);
                // for(int j=1;j<=c;j++)
                //     printf("%d ",now[j]);
                // puts("");
            }
            for(int i=1;i<=c;i++)
                ans[now[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}