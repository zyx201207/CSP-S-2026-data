#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],cnt[N],ans[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n; long long m;
    cin>>n>>m;
    int z=0;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        b[a[i]]++;
        z=max(b[a[i]],z);
    }
    sort(a,a+n);
    int l=1;
    int d=m;
    while(l<n) {
        for(int i=l-1;i>0;i--) {
             int k=a[l]-a[i];
             d-=a[i];
             ans[l]++;
             if(d<0) continue;

        }
        l++;
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
        cnt=max(cnt,ans[i]);
    }
    if(z>=2) cout<<cnt+z-1<<endl;
    else cout<<cnt<<endl;
    return 0;
}
