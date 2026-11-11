#include<bits/stdc++.h>
#define int long long
using namespace std;
int T=1;
int n,m,ans,sp;
int a[500001],b[500001],cf[500001],qzh[500001];
void init(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
map<int,int>ma;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!ma[a[i]]){
			sp++;
			b[sp]=a[i];
		}
		ma[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int st=0;
	for(int i=upper_bound(qzh+1,qzh+n+1,m)-qzh-1;i<=n;i++){
		if(qzh[i]-qzh[st]-st*(a[i]-a[st])<=m){
			ans=max(ans,i-st);
		}
		else{
			st++;
			int l=st,r=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(qzh[i]-qzh[mid]-mid*(a[i]-a[mid])<=m){
					r=mid-1;
					st=mid;
				}
				else{
					l++;
				}
			}
			ans=max(ans,i-st);
		}
	}
	cout<<ans;
	return;
}
signed main(){
	init();
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	while(T--){
		solve();
	}
	return 0;
}
