#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long a;
    int c;
};
Node a[200005];
Node c[200005];
int lc,ld;
Node d[200005];
char ch[10000005];
int n;
long long l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    long long maxn = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d %c",&a[i].a,&a[i].c);
        maxn = max(maxn,a[i].a);
        l += a[i].a;
    }
    if(n * maxn <= 10000005){
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= a[i].a;j++){
                cnt++;
                ch[cnt] = a[i].c;
            }
        }
        int ans = 0;
        for(int i = 1;i <= cnt / 2;i++){
            if(ch[i] != ch[cnt - i + 1]){
                ans++;
            }
        }
        printf("%d",ans);
        return 0;
    }
    int b;
    if(l % 2 == 0){
        b = 0;
    }else{
        b = 1;
    }
    l /= 2;
    long long tmp = l;
    //printf("tmp=%lld\n",tmp);
    int tmp2 = 0;
    for(int i = 1;i <= n;i++){
        if(tmp <= a[i].a){
            lc++;
            tmp2 = i;
            c[lc].a = tmp;
            c[lc].c = a[i].c;
            if(tmp == a[i].a){
                tmp2 = i + 1;
                tmp = 0;
            }
            break;
        }else{
            tmp -= a[i].a;
            lc++;
            c[lc].a = a[i].a;
            c[lc].c = a[i].c;
        }
    }
    for(int i = tmp2;i <= n;i++){
        if(i == tmp2){
            ld++;
            d[ld].a = a[i].a - tmp - b;
            d[ld].c = a[i].c;
        }else{
            ld++;
            d[ld].a = a[i].a;
            d[ld].c = a[i].c;
        }
    }
    /*
    for(int i = 1;i <= lc;i++){
        printf("%d c %d %c\n",i,c[i].a,c[i].c);
    }
    for(int i = 1;i <= ld;i++){
        printf("%d d %d %c\n",i,d[i].a,d[i].c);
    }
    */
    long long ans = 0;
    int i = 1,j = 1;
    while(i <= lc&&j <= ld){
        if(c[i].c != d[j].c){
            ans += min(d[j].a,c[i].a);
        }
        if(d[j].a > c[i].a){
            d[j].a -= c[i].a;
            i++;
        }else if(d[j].a < c[i].a){
            c[i].a -= d[j].a;
            j++;
        }else{
            i++;
            j++;
        }
    }
    printf("%lld",ans);
    return 0;
}

