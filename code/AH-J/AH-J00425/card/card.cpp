#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int l=0;
    vector<int>a(n+5,0),ans(m+5,0);
    for(int i=0;i<n;i++)cin>>a[i];

    bool bb=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>=a[i]){
            bb=1;
            break;
        }
    }
    if(bb==0){
        for(int i=0;i<m;i++)cout<<n<<' ';
        return 0;
    }
    for(int i=0;i<n;i++){
        vector<int>aa(n+5,0);
        l=0;
        for(int j=i;j<n;j++){
            if(a[j]==a[j+1])continue;
            int b=0;
            for(int jj=0;jj<l;jj++){
                if(aa[jj]==a[j]){
                    l=jj+1;
                    b=1;
                    break;
                }
            }
            if(b==0){
                aa[l]=a[j];
                l++;
            }
        }
    //xuyang isn't gay
        for(int j=0;j<l;j++)ans[aa[j]-1]++;
    }
    for(int i=0;i<m;i++)cout<<ans[i]<<' ';
    return 0;
}
