#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],cnt[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cout<<n<<" ";
    cout<<endl;
    return 0;
}
