#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],cf[500001],qz[500001],ans;
bool cmp(int u,int v){
    return u<v;
}
bool check(int mid1,int mid2){
    int cnt=0;
    for(int i=mid1;i<mid2;++i){
        cnt+=(qz[mid2-1]-qz[i-1]);
    }
    return cnt<=m;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<n;++i){
        cf[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;++i){
        qz[i]=qz[i-1]+cf[i];
    }
    for(int i=1;i<=n;++i){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid,i)){
                r=mid-1;
            }
            else{
                l=mid;
            }
        }
        if(check(l,i)){
			ans=max(ans,i-l+1);
		}
    }
	cout<<ans;
    return 0;
}
