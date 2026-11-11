#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("stding.out","w",stdout);
    long long S,n
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>S;
        a[i]--;
        S=i;
        ans=max(ans,s%n);
    }
    cout <<ans;
    return 0;

}
