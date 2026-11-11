#include <bits/stdc++.h>
using namespace std;
int a[2*10^5+5],c,ans,n;
char b[2*10^5+5];
string d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        for(int j=1;j<=a[i];j++){
            d+=b[i];
        }
        c+=a[i];
    }
    for(int i=0;i<c/2;i++){
        if(d[i]!=d[c-i-1]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
