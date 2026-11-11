#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n;
char c[N];
long long L=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i]>>c[i],L+=a[i];
    int l=1,r=n;
    long long suml=0,sumr=0,ans=0;
    while (l<r){
        while (suml+a[l]<=sumr+a[r]&&l<r){
            suml+=a[l];
            if (c[l]!=c[r])ans+=a[l];
            if (suml>=L/2){
                cout<<ans;
                return 0;
            }
            l++;cout<<suml+a[l]<<" "<<sumr+a[r]<<"\n";
        }
        if (l==r){
            cout<<ans;
            return 0;
        }
        while (sumr+a[r]<=suml+a[l]&&l<=r){
            sumr+=a[r];
            r--;
        }
    }
    cout<<ans;
    return 0;
}
