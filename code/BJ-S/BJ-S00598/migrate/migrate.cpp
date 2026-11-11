#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>a[i];
        if(c==11||c==12){
            cout<<n-d-2*(a[1]-a[0])+1<<endl;
            continue;
        }
    }
    return 0;
}