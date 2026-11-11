#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int k,n=0;
    cin>>k;
    for (int i=1;i<=k;i++){
        char c;
        int num;
        cin>>num>>c;
        n+=num;
        for (int j=1;j<=num;j++){
            s+=c;
        }
    }
    int ans=0;
    for (int l=0,r=n-1;l<r;l++,r--){
        if(s[l]!=s[r])ans++;
    }
    cout<<ans;
    return 0;
}
