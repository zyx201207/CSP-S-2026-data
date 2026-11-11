#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n;
long long len[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    long long l=1,r=n,ans=0;
    while(l<r){
        int L=min(len[l],len[r]);
        if(c[l]!=c[r]) ans+=L;
        len[l]-=L;
        len[r]-=L;
        if(len[l]==0) l++;
        if(len[r]==0) r--;
    }
    cout<<ans;
    return 0;
}
