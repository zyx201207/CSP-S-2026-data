#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int ans;
    int maxans=-1;
    for(int i=m;i<=n;i++){
        ans=a[i];
        for(int j=i-m+1;j<i;j++){
            ans=ans&a[j];
        }
        maxans=max(maxans,ans);
    }
    cout<<maxans;
    return 0;
}
