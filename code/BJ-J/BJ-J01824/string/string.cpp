#include <bits/stdc++bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,now=0,ans=0;
    char a[200010];
    for(int i=0;i<n;i++){
        int w;
        char x;
        cin>>w>>x;
        for(int j=0;j<w;j++){
            a[now]=x;
            now++;
        }
    }
    if(now%2==0){
        for(int i=0;i<now/2;i++)
            if(a[i]!=a[now-i])ans++;
    }
    else{
        for(int i=0;i<=now/2;i++)
            if(a[i]!=a[now-i])ans++;
    }
    cout<<ans;
    return 0;
}