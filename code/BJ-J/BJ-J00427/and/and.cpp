#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    long long n,m,ah[200001],oh=33554431;
    cin>>n>>m;
    if(m==n){
        for(long long i = 1;i<=n;i++){
            cin>>ah[i];
            oh=oh&ah[i];
        }
        cout<<oh;
        return 0;
    }
    for(long long i = 1;i<=n;i++){
        cin>>ah[i];
    }
    sort(ah+1,ah+n+1);
    for(long long i = n;i>=n+1-m;i--){
        oh=oh&ah[i];
    }
    cout<<oh;
    return 0;
}
