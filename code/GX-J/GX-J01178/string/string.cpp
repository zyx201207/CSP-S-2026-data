#include <bits/stdc++.h>
using namespace std;
long long n,k,len=0,ans=0;
char s[999999999],x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>x;
        for(int i=0;i<k;i++){
            s[len+i]=x;
        }
        len+=k;
    }
    int l=0,r=len-1;
    while(l<r){
        if(s[l]!=s[r]) ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
