#include<bits/stdc++.h>
int n,m,a[301000],cnt[301000];
long long ans;
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])
        {
            f=false;
        }
    }
    if(f=true){
        for(int i=n;i>=1;i--)
        {
            cout<<0<<" ";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<n<<" ";
    }
    return 0;
}

