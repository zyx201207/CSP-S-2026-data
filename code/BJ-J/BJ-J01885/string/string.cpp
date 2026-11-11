#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
long long ans;
pair<int,char> a[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    int r=n,l=1;
    char col=a[n].second;
    while(l<r){
        if(a[l].second==a[r].second){
            if(a[l].first<a[r].first) a[r].first-=a[l].first,l++;
            else if(a[l].first>a[r].first) a[l].first-=a[r].first,r--;
            else l++,r--;
        }
        else{
            ans+=min(a[l].first,a[r].first);
            if(a[l].first<a[r].first) a[r].first-=a[l].first,l++;
            else if(a[l].first>a[r].first) a[l].first-=a[r].first,r--;
            else l++,r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
