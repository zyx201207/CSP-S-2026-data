/*
graph or counting?
maybe O(N log{N})
---
rewrite
n points on number line
abs(x_i-x_j) <= d -> i&j are connected
find the number of pair(u,v) (u<v) under the restrain that
there are exactly two different minimum paths between u and v
---
x_{i+1}-x_i > d -> there are separated
---
how bf?
considering dp
using an array to count the number of previous points to here
wait it is fake
we should count the mininum path
emmm
first use floyd to calc mininum number
and then for each (u,v)
scan u < k < v and determine whether dis_{u,v}=dis_{u,k}+dis{k,v}
and count
time complexity O(N^3), expect 24 pts
---
can it be made to O(N^2)?
or O(N^2 log{N}) maybe OK
we know that if (u,v) legal
the path between u&v is like this:
u -(1)> a -(2)> b -(1)> v
---
well 
it is high time that i looked at the spp
A: x_1 ~ x_n constructs a sub-equal list
so it must have a good property
int k=d/delta_x
so (u,v) legal iff v-u==2*k-1
and the ans is {
    k==0 0
    else n-k
}

B: there is a island that can connect to any other islands
set it p
for u < p < v: 
    scan u < p

for u < v <= p or p <= u < v: 0
well well well
it is 17:52
and i have no time left
bf state starts!
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int kase,T,n;
ll d,a[N],dis[N][N],ans;
void bfsolve(){
    ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else if(abs(a[i]-a[j])<=d) dis[i][j]=1;
            else dis[i][j]=inf;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=i+3;j<=n;j++){
            int cnt=0;
            for(int k=i+1;k<=j-1;k++)
            if(dis[i][j]==dis[i][k]+dis[k][j]) cnt++;
            if(cnt==2) ans++;
        }
    cout<<ans<<'\n';
}

void sppasolve(){
    ll k=d/(a[2]-a[1]);
    if(k==0||k==1) cout<<0;
    else cout<<max(0ll,n+1-2*k)<<'\n';
}

void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(kase==11||kase==12) sppasolve();
    bfsolve();
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>kase>>T;
    while(T--) solve();
    return 0;
}
/*
code by A.Y.C.
qwq
*/
/*
failed to convert GOTPCREL relocation; relinked with --no-relax
collect2: error: ld return 1 exit status
what is this???
i can't repair it!
*/