#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
ll n,m,a[N],b[N],cnt;
map<long long,int> mp;
bool flaga=true,flagb=true;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(a[i-1]>a[i]) flaga=false;
    }
    if(flaga) for(int i=1;i<=m;i++) cout<<mp[i]*i<<" ";
    return 0;
}
