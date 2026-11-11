#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[200005],a[200005];
set<long long>st;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        cout<<n<<' ';
    }
    return 0;
}
