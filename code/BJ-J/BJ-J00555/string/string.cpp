#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    long long len=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for (int j=1;j<=a[i];j++){
            s+=c[i];
            len++;
        }
    }
    len-=1;
    int ans=0;
    for (long long i=0;i<=len/2;i++){
        if (s[i]!=s[len-i])ans++;
    }
    cout<<ans;
    return 0;
}
