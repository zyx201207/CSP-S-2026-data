#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define ll long long
#define pb push_back
#define vi vector<int>
#define fi first
#define se second
using namespace std;

const int N=5e5+5;
int n;
ll m,a[N],s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n)s[i]=s[i-1]+a[i];
    int ans=0;
    rep(i,1,n){
        int l=1,r=i+1;
        while(l<r){
            int mid=(l+r>>1);
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<'\n';

    return 0;
}



//guanzhufalidamiao,xiexiemiao
