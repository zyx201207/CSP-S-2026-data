//GZ-J00381 º«ÓúĞÅ
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
char c[200005];
int ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r){
        if(a[l]==a[r]){
            if(c[l]!=c[r]) ans+=a[l];
            l++,r--;
        }
        else if(a[l]<a[r]){
            a[r]-=a[l];
            if(c[r]!=c[l]) ans+=a[l];
            l++;
        }else{
            a[l]-=a[r];
            if(c[r]!=c[l]) ans+=a[r];
            r--;
        }
    }
    cout<<ans;
    return 0;
}
