#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int b[200010];
long long sum;

void dfs(int t,int cnt){
    if (t==n){
        if (cnt==m){
            long long ans=b[0];
            for (int i=1;i<m;i++) ans=ans&b[i];
            sum=max(sum,ans);
        }
        return;
    }
    if (cnt>m) return;
    b[cnt]=a[t];
    dfs(t+1,cnt+1);
    dfs(t+1,cnt);
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,j;
    cin>>n>>m;
    for (i=0;i<n;i++) cin>>a[i];
    if (m!=1&&m!=2) dfs(0,0);
    else if (m==1) for (i=0;i<n;i++) sum=max(sum,a[i]);
    else if (m==2)
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (i!=j) sum=max(sum,a[i]&a[j]);

    cout<<sum;
    return 0;
}
