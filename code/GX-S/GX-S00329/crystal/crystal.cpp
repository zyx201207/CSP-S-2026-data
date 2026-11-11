#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int r=1;
	int ans=0;
	for(int l=1;l<=n;l++){
		cnt-=a[r]-a[l];
		while(cnt<=m){
			if(r>n){
				break;
			}
			ans=max(ans,r-l+1);
			r+=1;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
	}
	cout<<ans;
	return 0;
}
