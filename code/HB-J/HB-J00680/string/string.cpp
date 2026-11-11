#include<bits/stdc++.h>
using namespace std;
long long n,l=0,ans=0,a;
char c,s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>c;
        for(long long  j=0;j<a;j++){
            l++;
            s[l]=c;
        }
    }
    for(long long i=1;i<=l;i++){
        if(s[i]!=s[l+1-i]){
            ans++;
            s[l+1-i]=s[i];
        }
    }
    cout<<ans;
    return 0;
    }
