#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a[200010];
LL l[200010],r[200010],ans=0;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);cin>>c[i];
    }
    l[1]=1;
    for(int i=2;i<=n;i++)l[i]=l[i-1]+a[i-1];
    r[n]=l[n]+a[n]-1;
    for(int i=n-1;i;i--)r[i]=r[i+1]-a[i+1];
    int L=1,R=n;LL li=1,ri=r[n];
    while(L<R){
        LL llen=r[L]-li+1,rlen=ri-l[R]+1;
        LL p=min(llen,rlen);
        if(c[L]!=c[R]){
            ans+=p;
        }
        li+=p;
        if(li>r[L])L++;
        ri-=p;
        if(ri<l[R])R--;
    }
    printf("%lld\n",ans);
}
