#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb puah_back

const int N=5e5+10,M=1e3+10;
int n,m,a[N];
bool qwe(int x){
    queue<int> q;
    int ans=0;
    for(int i=1;i<=x;i++){
        q.push(a[i]);
        ans+=a[x]-a[i];
    }
    if(ans<=m) return 1;
    for(int i=x+1;i<=n;i++){
        q.push(a[i]);
        ans-=a[i-1]-q.front();
        q.pop();
        ans+=(x-1)*(a[i]-a[i-1]);
        if(ans<=m) return 1;
    }
    return 0;

}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(l<r){
        int mid=l+r+1>>1;
        if(qwe(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}
