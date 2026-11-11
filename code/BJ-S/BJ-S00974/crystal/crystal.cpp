#include<bits/stdc++.h>
using namespace std;
const int NR=5e5+5;
int n;
long long m,a[NR],s[NR];
bool check(int x){
    deque<int> q;
    for(int i=1;i<=x;i++){
        while(!q.empty()&&a[q.back()]<a[i]) q.pop_back();
        q.push_back(i);
    }
    for(int i=1;i+x-1<=n;i++){
        int l=i,r=i+x-1;
        if(a[q.front()]*x-(s[r]-s[l-1])<=m) return 1;
        if(i+x<=n){
            while(!q.empty()&&a[q.back()]<a[i+x]) q.pop_back();
            q.push_back(i+x);
        }
        while(!q.empty()&&q.front()<=i) q.pop_front();
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("crystal4.in","r",stdin);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int x=(l+r)>>1;
        if(check(x)){
            ans=x;
            l=x+1;
        }
        else r=x-1;
    }
    printf("%d",ans);
    return 0;
}
