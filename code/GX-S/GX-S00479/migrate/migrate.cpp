#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+5;
typedef pair<ll,ll> P;
ll read(){
    char x = getchar();
    ll a = 1,ans = 0;
    while(x < '0'||x > '9'){
        if(x == '-')a = -1;
        x = getchar();
    }
    while(x >= '0'&&x <= '9'){
        ans = ans*10+x-'0';
        x = getchar();
    }
    return ans*a;
}
struct node{
    ll x,siz,len,ans;
}q[N];
void work(){
    ll n = read(),d = read();
    for(int i = 1;i <= n;i ++)q[i] = node{0,0,0,0};
    ll top = read();
    ll l = 1,r = 0,ans = 0;
    for(int i = 1;i < n;i ++){
        ll x = read();
        ll Tmp = l,len = 0,siz = 0,Ans = 0;
        while(l <= r&&q[l].x + d < x){
            if(l == Tmp){
                len = q[l].len;
                Ans += q[l].ans;
            }else if(l == Tmp+1&&q[l].siz){
                if(!q[l-1].siz)Ans += q[l].len;
                else Ans += q[l].siz;
            }
            siz ++;l ++;
        }
        len += siz;
        q[++r] = node{top,siz,len,Ans};top = x;
        if(q[r].x + d < x)l = r+1;
        //for(int i = l;i <= r;i ++){
        //    cout<<i<<" "<<q[i].siz<<" "<<q[i].len<<" "<<q[i].ans<<endl;
        //}cout<<endl;
        if(r-l+1 >= 2&&q[l+1].siz){
            ans +=  (q[l].siz == 0?q[l+1].len:q[l+1].siz);
            //cout<<"ans += "<<(q[l].siz == 0?q[l+1].len:q[l+1].siz)<<endl;
        }
        if(l<=r)ans += q[l].ans;//,cout<<"ans += "<<q[l].ans<<endl;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll CC = read(),TV = read();
    while(TV --){
        work();
    }
    return 0;
}
