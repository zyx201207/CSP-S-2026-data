#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0,ans=0;
    char c;
    cin>>n;
    char s[n+5];
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            cnt++;
            s[cnt]=c;
        }
    }
    for(int i=1;i<=cnt/2;i++){
        if(s[i]!=s[cnt+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
