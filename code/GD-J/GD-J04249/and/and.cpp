#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    int n,m,ans=0;
    ll s[N];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }sort(s+1,s+n+1,cmp);
    ans=s[1];
    for(int i=2;i<=m;i++){
        ans&=s[i];
    }
    cout<<ans;
}   