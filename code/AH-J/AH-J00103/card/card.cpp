#include <bits/stdc++.h>
using namespace std;

const int N=5e5+6,M=3e5+6;
int n,m,a[N],diff[N],ans[M];
vector<int> b[M];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int k=1;k<=m;k++) b[k].push_back(0);
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        b[a[i]].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b[a[i]].begin(),b[a[i]].end(),i)-b[a[i]].begin(),lst=b[a[i]][k-1];
        if (k==b[a[i]].size()-1) continue;
        for (int j=b[a[i]][k-1]+1;j<i;j++) {
            int k_=lower_bound(b[a[j]].begin(),b[a[j]].end(),j)-b[a[j]].begin();
            if (k_+1<b[a[j]].size()&&b[a[j]][k_+1]>i&&b[a[j]][k_+1]<b[a[i]][k+1]) lst=j;
        }
        diff[i]-=i-lst;
        diff[b[a[i]][k+1]]+=i-lst;
    }
    for (int i=1;i<=n;i++) {
        diff[i]+=diff[i-1]+1;
        ans[a[i]]+=max(diff[i],0);
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
