#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int>ans[500050];
int a[500050],output[300030];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int k=1;k<=n;++k)for(int i=k;i<=n;++i){
        int j=n;
        while(a[j]!=a[i] && j!=i)--j;
        ++output[a[i]];i=j;
    }for(int i=1;i<=m;++i)cout<<output[i]<<' ';
    return 0;
}
