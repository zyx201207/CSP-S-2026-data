#include <bits/stdc++.h>
using namespace std;
int s[200005][3];
int n,sl,x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        int b;
        cin>>b;
        string a;
        cin>>a;
        s[i][0]=a[0]-'a';
        s[i][1]=sl+1;
        sl+=b;
        s[i][2]=sl;
    }
    int ans=0;
    int l=0,r=sl;
    while(l<r){
        l++;
        for (int j=1;j<=n;j++){
            if (s[j][1]<=l && l<=s[j][2]){
                x=s[j][0];
                break;
            }
        }
        for (int j=n;j>=1;j--){
            if (s[j][1]<=r && r<=s[j][2]){
                y=s[j][0];
                break;
            }
        }
        if (x!=y){
            ans++;
        }
        r--;
    }
    cout<<ans;
    return 0;
}
