#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans;
    sort(a+1,a+n+1,greater<long long>());
    for(int i=1;i<=m;i++){
        if(i==1){
            ans=a[i];
        }else{
            ans&=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
