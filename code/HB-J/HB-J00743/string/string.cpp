#include <bits/stdc++.h>
using namespace std;
int n,a,cnt,ans;
char c,s[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s[cnt]=c;
            cnt++;
        }
    }

    for(int i=0;i<cnt/2;i++){
        if(s[i]!=s[cnt-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
