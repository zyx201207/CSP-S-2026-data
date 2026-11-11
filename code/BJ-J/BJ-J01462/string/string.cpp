#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }int l=1,r=n;long long ans=0;
    long long cnt=0;
    while(l<=r){
        if(a[l]==0)l++;
        if(a[r]==0)r--;
        if((a[l]==a[r]&&c[l]==c[r])||(c[l]==c[r]&&r-l==1)){
            if(cnt>0){ans+=cnt;}cnt=0;
        }
        else if(c[l]==c[r]){
            a[r-1]-=a[l]-a[r];
            ans+=abs(a[l]-a[r]);
        }else if(a[l]==a[r]){
            ans+=a[r];
        }else{
            a[r-1]-=a[l]-a[r];
            ans+=a[l];cnt=a[r]-a[l];
        }l++;r--;
    }
    cout<<ans<<'\n';
    return 0;
}