#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+5;
int a[N]={};
int sum[N]={};
char c[N]={};
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int l=0,r=s.size();
    int ans=0;
    while(l<r){
        if(s[l]!=s[r]) ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}
