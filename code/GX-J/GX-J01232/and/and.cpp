#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    ans=a[0];
    for(int i=1;i<m;i++)ans=ans&a[i];
    cout<<ans;
}
