#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
char c[200005];
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    int x=s.size();
    for(int i=0;i<=x/2;i++)if(s[i]!=s[x-i-1])ans++;
    cout<<ans;
    return 0;
}
