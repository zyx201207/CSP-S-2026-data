#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+!0;
long long arr01[N],arr02[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>arr01[i];
    sort(arr01+1,arr01+n+1);
    for(int i=1;i<=n;++i)
        arr02[i]=arr01[n-i+1];
    for(int i=1;i<=n;++i)
        arr01[i]=arr02[i];
    int k=arr01[1];
    for(int i=2;i<=m;++i)
        k&=arr01[i];
    cout<<k<<'\n';
    return 0;
}
