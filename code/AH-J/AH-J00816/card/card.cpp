#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m,a[N],ans[M],l;
vector<int>vec[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        l++;
        ans[a[i]]=max(ans[a[i]],l);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
