#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n;
    while(r>l){
        long long k=min(a[l],a[r]);
        a[l]-=k; a[r]-=k;
        if(c[l]!=c[r]){
            ans+=k;
        }
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    return 0;
}
