#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
struct node{
    int len;
    char c;
};
node a[maxn];
int n;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].c;
    }
    int l=1,r=n;
    ll ans=0;
    while(l<r){
        int minlen=min(a[l].len,a[r].len);
        //cout<<l<<' '<<r<<'\t'<<a[l].len<<' '<<a[r].len<<' '<<minlen<<'\n';
        if(a[l].c!=a[r].c){
            ans+=(ll)minlen;
        }
        a[l].len-=minlen;
        a[r].len-=minlen;
        if(!a[l].len){
            l++;
        }
        if(!a[r].len){
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
