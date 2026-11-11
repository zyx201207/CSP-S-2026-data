#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    cout>>ans;


    return 0;
}
