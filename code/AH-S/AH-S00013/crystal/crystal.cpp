#include<bits/stdc++.h>
using namespace std;
using int64=long long;
const int N=5e5+5;
int64 n,m,a[N];
bool check(int x){
    int64 tmp=0,cnt=0;
    for(int i=1;i<x;++i){
        tmp+=a[x]-a[i];
    }cnt=tmp;
    for(int i=x+1;i<=n;++i){
        tmp-=a[i-1]-a[i-x];
        tmp+=(a[i]-a[i-1])*x;
        cnt=(cnt>tmp?tmp:cnt);
    }return cnt<=m;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }cout<<l;
	return 0;
}
