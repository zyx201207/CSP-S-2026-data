#include <bits/stdc++.h>

using namespace std;
int n,m;
long long a[200010];
long long sum=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        long long tx=a[i];
        for(int j=1;j<m;j++){
            tx=tx&a[i+j];
        }
        sum=max(sum,tx);
    }
    cout<<sum;
    return 0;
}
