#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,andd[100010],a[100010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    andd[0]=a[0];
    for(int i=0;i<n-m;i++){
        for(int j=i;j<i+m;j++){
            andd[i]=andd[i]&a[j];
        }
        ans=max(andd[i],ans);
    }
    sort(a,a+n,greater<int>());
    andd[0]=a[0];
    for(int i=0;i<n-m;i++){
        for(int j=i;j<i+m;j++){
            andd[i]=andd[i]&a[j];
        }
        ans=max(andd[i],ans);
    }
    cout<<ans;
    return 0;
}
