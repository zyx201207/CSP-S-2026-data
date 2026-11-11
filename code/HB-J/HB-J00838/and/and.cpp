#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],ma,ans=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n+m;i++){
        ma=a[i];
        for(int j=i+1;j<i+m;j++){
            ma&=a[j];
        }
        ans=max(ans,ma);
    }
    cout<<ans;
    return 0;
}
