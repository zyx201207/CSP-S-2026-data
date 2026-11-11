#include <bits/stdc++.h>
using namespace std;
bool nt[200005][35],ans[35],v[200005];long long x,a[200005];int n,m,cnt[35],maxn=0,vis=0;
int bin(int l,int r,int dep){
	int ans=0; 
	while (l<=r){
		int mid=(l+r)>>1;
		if (nt[mid][dep]) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		x=a[i];
		int idx=0;
		while (x){
			nt[i][++idx]=x%2;
			cnt[idx]+=x%2;
			x/=2;
		}
		maxn=max(maxn,idx);
	}
	for (int i=maxn;i>=1;i--){
		if (cnt[i]<m) continue;
		if (vis==0){
			vis=bin(1,n,i);
		}
		int nnt=0;
		for (int j=vis;j<=n;j++){
			if (v[j]) continue;
			nnt+=nt[j][i];
		}
		if (nnt<m) continue;
		ans[i]=1;
		for (int j=vis;j<=n;j++){
			if (v[j]) continue;
			v[j]=!nt[j][i];
		}
	}
	x=0;
	long long p2=1;
	for (int i=1;i<=maxn;i++){
		x+=p2*ans[i];
		p2*=2;
	}
	cout<<x<<endl; 
	return 0;
} 
