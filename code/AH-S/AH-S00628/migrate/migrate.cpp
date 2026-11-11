#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}return f*x;}
const int N=2e6+5;
int _,T;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    _=read(),T=read();
    while(T--){
        int n=read(),d=read();
        rep(i,1,n)a[i]=read();
        int s=0,i=1;
        while(a[i]+d<a[n]){
            auto it=upper_bound(a+1,a+n+1,a[i]+d)-1;
            if(it-a==i+1){i++;continue;}
            int x1,x2,s1,s2;s1=s2=1;
            it--;
            x2=*it;it--;x1=*it;
            auto it1=upper_bound(a+1,a+n+1,x1+d);
            auto it2=upper_bound(a+1,a+n+1,x2+d);
            it1--;it2--;
            if(it1-a==n+1)break;
            if(it2-it1>=1){
                //printf("#%lld %lld %lld\n",i,x1,x2);
               // printf("*%lld %lld\n",*it1,*it2);
                int pre=0;
                req(j,i-1,1){
                    if(a[j+1]-a[j]>d)break;
                    int l=a[i]-a[j],r=a[i+1]-a[j];
                    int t=l/d,x3;
                    if(t-pre>1)break;
                    pre=t;
                    x3=a[j]+t*d;
                    if(a[i]<=x3&&x3<a[i+1])s1++;
                }
                int h=it2-a,h1=*it1,h2=*it2;pre=0;
                rep(j,h+1,n){
                    if(a[j]-a[j-1]>d)break;
                    int l=a[j]-h1,r=a[j]-h2;
                    int t=l/d,x3;
                    if(t-pre>1)break;
                    pre=t;
                    x3=a[j]-t*d;
                    if(h1<x3&&x3<=h2)s2++;
                }
                s+=(it2-it1)*s1*s2;
                //printf("##%lld %lld\n",s1,s2);
            }
            i++;
        }
        printf("%d\n",s);
    }
    return 0;
}

