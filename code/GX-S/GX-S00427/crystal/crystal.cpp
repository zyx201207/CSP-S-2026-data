#include<bits/stdc++.h>//20think
using namespace std;
#define ll long long
ll n,m,c[500009],d[500009],l,r,nowsum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
            d[i-1]=c[i]-c[i-1];
    }
    l=r=1;
    for(ll i=1;i<=n;i++){
		if(r<l){
				r=l;
		}
            nowsum-=c[r]-c[l];
        l=i; 
        while(nowsum<=m&&r<=n){
           r+=1;
            nowsum+=(r-l)*d[r-1]*1LL;
            if(nowsum>m){
					r-=1;
					nowsum-=(r-l+1)*d[r]*1LL;
					break;
			}
        }
        
        
        ans=max(r-l+1,ans);
    }
    cout<<ans;
    return 0;
}
