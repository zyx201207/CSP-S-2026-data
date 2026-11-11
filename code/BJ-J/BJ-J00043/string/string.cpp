#include<bits/stdc++.h>
using namespace std;
struct Node{
    long long x;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    unsigned long long ans=0;
    for(int i=1;i<=n/2;i++){
        if(a[i].c==a[i+(int)ceil(double(n/2.0))].c) ans+=abs(a[i].x-a[i+(int)ceil(double(n/2.0))].x);
        else ans+=min(a[i].x,a[i+(int)ceil(double(n/2.0))].x);
    }
    cout<<ans<<'\n';
    return 0;
}