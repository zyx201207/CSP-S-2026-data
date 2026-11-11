#include<bits/stdc++.h>
using namespace std;
long long ans,n,a,cnt,p,q;
char z[250000005],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            z[++cnt]=c;
        }
    }
    p=1;
    q=cnt;
    for(int i=1;i<=cnt/2;i++){
        if(z[p]!=z[q])ans++;
        p++;
        q--;
    }
    cout<<ans;
    return 0;
}
