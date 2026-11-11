#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
struct node{
    ll len;
    char ch;
}a[N],b[N],c[N];
ll sum,ans,cb,cc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i].len,&a[i].ch);
        sum+=a[i].len;
    }
    for(int i=1,j=n;i<j;){
        if(a[i].len==a[j].len){
            b[++cb]={a[j].len,a[i].ch};
            c[++cc]={a[j].len,a[j].ch};
            j--;i++;
        }
        if(a[i].len>a[j].len){
            b[++cb]={a[j].len,a[i].ch};
            c[++cc]={a[j].len,a[j].ch};
            a[i].len-=a[j].len;j--;
        }
        if(a[i].len<a[j].len){
            b[++cb]={a[i].len,a[i].ch};
            c[++cc]={a[i].len,a[j].ch};
            a[j].len-=a[i].len;i++;
        }
    }
    //for(int i=1;i<=cb;i++) printf("%lld %c                     %lld %c\n",b[i].len,b[i].ch,c[i].len,c[i].ch);
    int cnt=min(cb,cc);
    for(int i=1;i<=cnt;i++){
        if(b[i].ch!=c[i].ch) ans+=b[i].len;

    }
    printf("%lld",ans);
    return 0;
}
