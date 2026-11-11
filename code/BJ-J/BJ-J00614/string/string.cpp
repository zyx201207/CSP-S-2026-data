#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],sum[1000005],b[1000005],ans;
char c[1000005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    int mid=(s.size()+1)/2-1;
    for(int i=0;i<s.size();i++){
        if(i>=mid){
            if(s[s.size()-i-1]!=s[i]){
                ans++;
                s[s.size()-i-1]=s[i];
            }
        }
    }cout<<ans;
    return 0;
}
