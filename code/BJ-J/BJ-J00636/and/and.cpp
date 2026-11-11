#include<bits/stdc++.h>
using namespace std;
int n,m,p2[33],cnt[33];
struct Node {
    int id,t[33];
}a[200010];
int k[200010];
bool cmp(Node x,Node y) {
    for(int i=30;i>=0;i--)
        if(cnt[i]==1&&x.t[i]!=y.t[i])
            return x.t[i]>y.t[i];
    return x.id<y.id;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    p2[0]=1;
    for(int i=1;i<=30;i++) p2[i]=p2[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>k[i];
        x=k[i];
        a[i].id=i;
        for(int j=30;j>=0;j--) {
            if(x>=p2[j]) {
                cnt[j]++;
                x-=p2[j];
                a[i].t[j]=1;
            }
        }
    }
    for(int i=30;i>=0;i--) {
        if(cnt[i]>=m) cnt[i]=1;
        else cnt[i]=0;
    }
    sort(a+1,a+n+1,cmp);
    long long ans=k[a[1].id];
    for(int i=2;i<=m;i++)
        ans&=k[a[i].id];
    cout<<ans;
    return 0;
}

