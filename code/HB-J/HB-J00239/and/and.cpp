#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
long long n,m,ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<>());
    ans+=a[0];
    for(int i=1;i<m;i++){
        ans&=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
