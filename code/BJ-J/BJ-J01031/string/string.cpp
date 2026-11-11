#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x;
    char c;
}a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].c;
    int l=1,r=n;
    int ans=0;
    while(l<r){
        if(a[l].c!=a[r].c)
            ans+=min(a[l].x,a[r].x);
        if(a[l].x>a[r].x){
            a[l].x-=a[r].x;
            r--;
        }
        else if(a[l].x<a[r].x){
            a[r].x-=a[l].x;
            l++;
        }
        else{
            a[r].x=a[l].x=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
