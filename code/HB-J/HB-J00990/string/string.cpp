#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,q[200005],h[200005],ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        q[i]=q[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        h[i]=h[i+1]+a[i];
    }
    int j=n;
    for(int i=1;i<=n;i+=0){
        if(j<=0)break;
        if(c[j]==c[i]){
            ans+=min(q[i],h[j])-max(h[j+1],q[i-1]);
        }
        if(q[i]<h[j])i++;
        else{
            j--;
        }
    }
    ans=h[1]-ans;
    ans=ans/2;
    cout<<ans;
    return 0;
}
