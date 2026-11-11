#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,b[1000001],l=1,r,ans;
char a[1000001];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n,r=n;
    for(int i=1;i<=n;i++)cin>>b[i]>>a[i];
    while(l<r){
        if(a[l]==a[r]){
            if(b[l]>b[r])b[l]-=b[r],r--;
            else if(b[l]<b[r])b[r]-=b[l],l++;
            else l++,r--;
        }
        else{
            if(b[l]>b[r])ans+=b[r],b[l]-=b[r],r--;
            else if(b[l]<b[r])ans+=b[l],b[r]-=b[l],l++;
            else ans+=b[l],l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
