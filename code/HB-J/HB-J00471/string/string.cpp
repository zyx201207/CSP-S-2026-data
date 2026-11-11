#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,p;
char x[200005],s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
        for(int j=1;j<=a[i];j++)
            s[++p]=x[i];
    }

    for(int i=1;i<=p/2;i++){
        if(s[i]!=s[p-i+1])
        ans++;
    }
    cout<<ans;
    return 0;
}
