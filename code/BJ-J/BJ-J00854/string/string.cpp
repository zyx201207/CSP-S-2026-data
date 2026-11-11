#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long zl=0;
    cin>>n;
    string s,s1;
    for(int i=0;i<n;i++){
        int x;
        char c;
        cin>>x>>c;
        a[i]=x;
        s+=c;
        zl+=x;
    }
    long long cnt=0,le=0;
    int k=0,i=n-1;
    while(le<=zl/2&&k<=n){
        int js=min(a[i],a[k]);
        a[i]-=js;
        a[k]-=js;
        le+=js;
        if(s[i]!=s[k]){
            cnt+=js;
        }
        if(a[i]<=0)i--;
        if(a[k]<=0)k++;
    }
    cout<<cnt;
    return 0;
}
