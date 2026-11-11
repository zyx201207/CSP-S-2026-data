#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(((ans|(1<<i))&a[j])==(ans|(1<<i)))cnt++;
        }
        if(cnt>=m)ans|=(1<<i);
    }
    cout<<ans<<endl;
    return 0;
}



