#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,d=0,cnt=0;
    cin>>n;
    string a,b,c;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(a[i]>0;a[i]--){
            c[d]==b;
            }
        }
    for(int i=1;i<=n/2;i++){
        if(b[i]!=b[n+1-i])cnt+=min(a[i],a[n+1-i]);}
    cout<<cnt;
    return 0;
}
