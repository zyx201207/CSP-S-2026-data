#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<string,int> a[200005];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].second>>a[i].first;
    }
    int l=1,r=n;
    int ans=0;
    while(l<=r){
        if(a[l].first==a[r].first){
            if(a[l].second>a[r].second){
                a[l].second-=a[r--].second;
            }
            else if(a[l].second==a[r].second){
                l++,r--;
            }
            else{
                a[r].second-=a[l++].second;
            }
        }
        else{
            if(a[l].second>a[r].second){
                ans+=a[r].second;
                a[l].second-=a[r--].second;
            }
            else if(a[l].second==a[r].second){
                ans+=a[r].second;
                l++,r--;
            }
            else{
                ans+=a[l].second;
                a[r].second-=a[l++].second;
            }
        }
    }
    cout<<ans;
}
