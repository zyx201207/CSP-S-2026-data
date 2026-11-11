#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005],b[200005],ans,len=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--) b[++len]=a[i];
    ans=b[1];
    for(int i=2;i<=m;i++){
        ans=ans&b[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
