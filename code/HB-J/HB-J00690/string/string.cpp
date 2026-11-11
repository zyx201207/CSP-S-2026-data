#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
struct node{
    ll x,y;
    char c;
}e[N];
ll n,ans,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        ll m;
        scanf("%lld %c",&m,&e[i].c);
        e[i].x=cnt+1,cnt+=m,e[i].y=cnt;
    }
    ll l=1,r=n,mid;
    if(cnt%2==1)
        mid=cnt/2+1;
    else
        mid=cnt/2;
    while(l<r){
        ll x1=e[l].x,y1=e[l].y,x2=e[r].x,y2=e[r].y;
        if(cnt%2==1){
            if(abs(x1-mid)>abs(y2-mid))
                x1=mid-(abs(y2-mid));
            else if(abs(x1-mid)<abs(y2-mid))
                y2=mid+(abs(x1-mid));
            if(abs(y1-mid)<abs(x2-mid))
                y1=mid-abs(mid-x2);
            else if(abs(y1-mid)>abs(x2-mid))
                x2=mid+abs(mid-y1);
            if(e[l].c!=e[r].c)
                ans+=(y1-x1+1);
            if(abs(e[l].y-mid)>abs(e[r].x-mid))
                l++;
            else if(abs(e[l].y-mid)<abs(e[r].x-mid))
                r--;
            else
                l++,r--;
        }
        else{
            if(abs(mid-x1+1)>abs(y2-mid))
                x1=mid+1-(abs(y2-mid));
            else if(abs(mid-x1+1)<abs(y2-mid))
                y2=mid+(abs(mid-x1+1));
            if(abs(mid-y1+1)<abs(x2-mid))
                y1=mid+1-abs(mid-x2);
            else if(abs(mid-y1+1)>abs(x2-mid))
                x2=mid+abs(mid-y1+1);
            if(e[l].c!=e[r].c)
                ans+=(y1-x1+1);
            if(abs(mid-e[l].y+1)>abs(e[r].x-mid))
                l++;
            else if(abs(mid-e[l].y+1)<abs(e[r].x-mid))
                r--;
            else
                l++,r--;
        }
    }
    printf("%lld",ans);
    return 0;
}
