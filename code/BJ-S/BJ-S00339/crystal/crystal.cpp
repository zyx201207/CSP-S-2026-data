#include <bits/stdc++.h>
#define int long long
using namespace std;
int crystal[500010];
int original[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>crystal[i];
    sort(crystal+1,crystal+n+1);
    for (int i=1;i<=n;i++){
        original[i]=crystal[i];
        crystal[i]+=crystal[i-1];
    }
    int answer=1;
    for (int l=1;l<=n;l++)
        for (int r=l+answer;r<=n;r++){
            //cout<<l<<"~"<<r<<" "<<original[r]<<" ";
            int need=original[r]*(r-l+1)-(crystal[r]-crystal[l-1]);
            //cout<<need<<endl;
            if (need>m) break;
            else answer=max(answer,r-l+1);
        }
    cout<<answer<<endl;
    return false;
}
