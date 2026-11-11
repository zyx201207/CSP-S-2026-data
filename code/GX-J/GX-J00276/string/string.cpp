#include <bits/stdc++.h>
using namespace std;
int n,m,len,ans=0;
string c="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string c1;
        cin >> m >> c1;
        for(int j=1;j<=m;j++){
            c+=c1;
        }
    }
    len = c.size();
    for(int i=1;i<=len/2;i++){
        if(c[i-1]!=c[len-i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
