# include <bits/stdc++.h>
using namespace std;
const int CLS=2e5+10;
int a[CLS],n;
char c[CLS];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long left=0,right=0,ans=0;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>c[i];
        if(i==1) left=a[i];
        right+=a[i];
    }
    int l=1,r=n,mid=n/2;
    while(l<=r){
        if(c[l]!=c[r]) ans+=min(a[l],a[r]);
        if(a[l]==a[r]) l++,r--;
        else if(a[l]>a[r]) a[l]-=a[r],r--;
        else               a[r]-=a[l],l++;
    }
    cout<<ans;
    return 0;
}
