#include<bits/stdc++.h>
using namespace std;
const int N=2e8+5;
int n,s[N],a[N],ans=0;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n-1;i++){
        if(m-s[i+1]*i>=0){
            m-=i*s[i+1];
            ans++;
        }
        else break;
    }cout<<ans+1<<endl;
    return 0;
}
