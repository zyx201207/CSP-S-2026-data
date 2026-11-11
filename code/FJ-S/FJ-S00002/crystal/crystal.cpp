#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],b[MAXN],c[MAXN],d[MAXN];
long long m;
int n;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
		d[i]=d[i-1]+b[i]*(i-1LL);
	}
	int ans=0;
	for(int s=1;s<=n;s++){
		int l=s,r=n,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(d[mid]-d[s]-(s-1LL)*(c[mid]-c[s])<=m){
				l=mid+1;
				res=mid-s+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}