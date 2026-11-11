#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e17;
map<long long,long long> v;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        long long a;
        scanf("%lld",&a);
        v[a]++;
    }
    for(auto it=v.begin();it!=v.end();it++){
        auto p=it;
        long long s=m,cnt=it->second,mb=it->first;
        while(p!=v.begin()&&s){
            p--;
            long long cmd=p->second,md=p->first;
            long long cha=mb-md;
            if(cha*cmd<=s){
                s-=cha*cmd;
                cnt+=cmd;
            }else{
                cnt+=(s/cha);
                break;
            }
        }
        maxn=max(maxn,cnt);
    }
    cout<<maxn;
    return 0;
}
