#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<>());
    long long c=a[1]-a[2],j=1,ans=0;
    bool f=true;
    while(m>0){
        m-=c*j;
        ans++;
        j++;
    }
    if(m<0) ans--;
    cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
