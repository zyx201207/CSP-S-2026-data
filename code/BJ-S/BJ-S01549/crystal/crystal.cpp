#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N=5e5+5;

ll a[N];
ll sum[N];
int n;
ll m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int j=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        while(j<=i && a[i]*(i-j+1)-(sum[i]-sum[j-1])>m)j++;
        if(j<=i){
            ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}