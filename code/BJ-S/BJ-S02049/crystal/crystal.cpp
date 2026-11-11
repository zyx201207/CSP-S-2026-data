#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long a[N];
long long m;
long long res;
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    ans=1;
    int i=1;
    for(int j=2;j<=n;j++){
        res+=(j-1-i+1)*(a[j]-a[j-1]);
        while(res>m){
            res-=(a[j]-a[i]);
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
