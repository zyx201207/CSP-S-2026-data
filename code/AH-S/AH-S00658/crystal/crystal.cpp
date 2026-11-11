#include<bits/stdc++.h>
using namespace std;

long long n,m,ans,cnt;
long long a[500100],b[500100];

int BF(){
    long long M=m;
    for(int i=0;i<n;i++){
        cnt=0;
        M=m;
        for(int j=1;M>=0&&i+j<n;j++){
            cnt++;
            M-=cnt*(a[i+j]-a[i+j-1]);
            // cout<<cnt<<" "<<M<<"\n";
            if(M>=0&&i+j>=n) break;
        }
        ans=max(ans,cnt);
        // cout<<"\n"<<ans<<"\n";
    }
    return 0;
}
int solve(){
    int c=a[1]-a[0];
    int sum=0;
    for(cnt=1;sum<=m;cnt++){
        sum=c*(cnt*(cnt-1))/2;
    }
    ans=cnt-2;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n*n<=50000000) BF();
    else solve();
    cout<<ans;
    return 0;
}