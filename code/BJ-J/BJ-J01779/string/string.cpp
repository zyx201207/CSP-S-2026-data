#include<bits/stdc++.h>
using namespace std;
int n,s=0,k=0,ans=0;
int a[200005];
char c[200005];
string ss;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
        for(int j=1;j<=a[i];j++)ss+=c[i];
    }
    if(s%2==0)k/=2;
    else k=(s+1)/2;
    int l=ss.size()-1;
    for(int i=0;i<=l/2;i++){
        if(ss[i]!=ss[l-i])
            ans++;
    }
    cout<<ans;
return 0;
}
