#include<bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=1;
    for(int i=0;i<m;i++){
        int cnt=1;
        for(int j=i+1;j<n&&a[j]-a[i]<m;j++){
                cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}
