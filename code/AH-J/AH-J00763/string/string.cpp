#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[1000005],cnt;
char c[1000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        while(x[l]){
            if(l==r){
                break;
            }
            int tmp=min(x[l],x[r]);
            x[l]-=tmp;
            x[r]-=tmp;
            if(c[l]!=c[r]){
                cnt+=tmp;
            }
            if(x[l]){
                r--;
            }
        }
        l++;
    }
    cout<<cnt;
    return 0;
}
