#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll num[N];
char wd[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>wd[i];
    }
    ll ans=0;
    int pos1=1,pos2=n;
    while(pos1<pos2){
        ll sk=min(num[pos1],num[pos2]);
        num[pos1]-=sk;
        num[pos2]-=sk;
        if(wd[pos1]!=wd[pos2]) ans+=sk;
        if(!num[pos1]) pos1++;
        if(!num[pos2]) pos2--;
    }
    cout<<ans;
    return 0;
}