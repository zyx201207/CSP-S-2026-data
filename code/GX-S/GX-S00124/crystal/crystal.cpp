#include<bits/stdc++.h>
using namespace std;
long long lis[500005];
long long n,m;
queue<long long>q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i = 0;i<n;i++){
        scanf("%lld",&lis[i]);
    }sort(lis,lis+n);
    long long use=0,maxn=0,ans=-1;
    for(int i = 0;i<n;i++){
        long long last=0;
        if(i>0)last = lis[i]-lis[i-1];
        maxn=lis[i];
        q.push(lis[i]);
        use+=last*(q.size()-1);
        while(use>m){
            long long x=q.front();
            use-=maxn-x;
            q.pop();
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans;
}
