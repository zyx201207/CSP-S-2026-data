#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN];
int n,m;
int ans=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        int target=a[i];
        int ans_case=1;
        int cost=0;
        for(int j=i-1;j>=1;j--){
            cost+=target-a[j];
            if(cost<=m){
                ans_case++;
            }
            else break;
        }
        ans=max(ans,ans_case);
    }
    cout<<ans;
    return 0;
}
