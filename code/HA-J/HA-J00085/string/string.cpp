#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n,ll=a[1],rr=a[n];l<=r;){
		if(c[l]==c[r]){
			if(ll>=rr){
				r--;
				ll-=rr;
				if(ll==0){
					l++;
					ll=a[l];
				}
				rr=a[r];
			}else{
				l++;
				rr-=ll;
				ll=a[l];
			}
		}else{
			ans+=min(ll,rr);
			if(ll>=rr){
				r--;
				ll-=rr;
				if(ll==0){
					l++;
					ll=a[l];
				}
				rr=a[r];
			}else{
				l++;
				rr-=ll;
				ll=a[l];
			}
		}
	}
	cout<<ans;
	return 0;
}
