#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=2e5+7;

int T,n,m,mx=0,ans;
int a[N];
vector<int> e[35];
bool cmp(int x,int y) {
    return x>y;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]==0) e[32].push_back(a[i]);
        mx=max(mx,(int)(log2(a[i])));
        e[(int)(log2(a[i]))].push_back(a[i]);
    }
    sort(a+1,a+n+1,cmp);
    if(a[m]==0) {
        cout<<0;
        return 0;
    }
    bool flag=0;
    int mx2=mx;
    while(e[mx].size()<m&&mx>=0) mx--;
    if(e[mx].size()<m) flag=1;
        if(flag) {

            ans=a[1];
            for(int i=1;i<=m;i++) {
                ans=(int)(ans&a[i]);
            }
        }
        else {
            sort(e[mx].begin(),e[mx].end(),cmp);
            ans=e[mx][0];
            for(int i=1;i<m;i++) ans=(int)(ans&e[mx][i]);
        }

    cout<<ans;
    return 0;
}
