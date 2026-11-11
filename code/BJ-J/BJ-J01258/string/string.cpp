#include <bits/stdc++.h>
using namespace std;
struct p{
    char ch;
    long long much;
}a[200005];
long long n,ans,sum,ans_minus,sum2,t=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        char y;
        cin>>x>>y;
        if(i>1&&a[t].ch!=y){
            t++;
        }
        a[t].much+=x;
        a[t].ch=y;
        sum+=a[t].much;
    }
    long long lq=1,rq=t;
    while(lq<rq){
        if(a[lq].much==a[rq].much&&a[lq].ch!=a[rq].ch){
            ans+=a[lq].much;
            rq--;
            lq++;
        }
        else if(a[lq].much>a[rq].much&&a[lq].ch!=a[rq].ch){
            ans+=a[rq].much;
            a[lq].much-=a[rq].much;
            rq--;
        }
        else if(a[rq].much>a[lq].much&&a[lq].ch!=a[rq].ch){
            ans+=a[lq].much;
            a[rq].much-=a[lq].much;
            lq++;
        }
        else if(a[lq].ch==a[rq].ch&&a[rq].much>a[lq].much){
            a[rq].much-=a[lq].much;
            lq++;
        }
        else if(a[lq].ch==a[rq].ch&&a[rq].much<a[lq].much) a[lq].much-=a[rq].much,rq--;
        else{
            lq++;
            rq--;
        }
    }
    cout<<ans;
    return 0;
}
