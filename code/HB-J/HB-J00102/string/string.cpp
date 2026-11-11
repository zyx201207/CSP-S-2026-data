#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,ans=0;
    string s;
    cin>>n;
    vector<int> a(n+2);
    vector<char> c(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<=j;){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>=a[j]){
            a[i]-=a[j];
            a[j]=0;
        }
        if(a[i]<a[j]){
            a[j]-=a[i];
            a[i]=0;
        }
        if(a[i]==0)i++;
        if(a[j]==0)j--;
    }
    cout<<ans;
    return 0;
}
