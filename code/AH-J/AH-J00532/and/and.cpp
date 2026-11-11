#include<iostream>
#include<algorithm>
using namespace std;
using LL =long long;
const LL N = 2e5+5;

LL n,m,ans,maxn,a[N];
string counts(LL x){
    string ans="";
    LL cnt=0;
    while(x){
        char w=x%2+'0';
        ans=w+ans;
        x/=2;
    }
    return ans;
}
//bool cmp(const Node &x,const Node &y){
    //return
//}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxn=max(maxn,a[i]);
        //a[i].bin=counts(a[i].num);
    }
    if(m==n){
        ans=a[1]&a[2];
        for(LL i=3;i<=n;i++)
            ans=ans&a[i];
    }
    else if(m==1)ans=maxn;

    cout<<ans;
    return 0;
}
