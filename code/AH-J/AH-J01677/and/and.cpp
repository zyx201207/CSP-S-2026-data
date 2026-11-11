#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),cmp);
    int ans=a[0];
    for(int i=1;i<k;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
