#include <bits/stdc++.h>
using namespace std;
const int maxx=2*1e5+10;
long long n,m,a[maxx];
int jk(string ans){
    for(int i=1;i<=n;i++){
        int h=a[i];
        while(h!=0){
            ans+=(h%2)-'0';
            h/=10;
        }
    }
    reverse(ans.begin(),ans.end());
    int pos=ans-'0';
    return ans;
}
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           int len=jk(a[i])&jk(a[j]);
        }
    }
    cout<<len;
    return 0;
}
