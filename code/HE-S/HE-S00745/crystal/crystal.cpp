#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=500005,INF=0x3f3f3f3f;
ll n,m,a[MAXN],ans,sum[MAXN],q[MAXN],head=1,tail=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int r=1,l=1;r<=n;r++){
		while(l<=r&&head<=tail&&a[q[head]]*(r-l+1)-sum[r]+sum[l-1]>m){
			l++;
			if(q[head]<l)head++;
		}
		while(head<=tail&&a[r]>=a[q[tail]])tail--;
		q[++tail]=r;
		if(a[q[head]]*(r-l+1)-sum[r]+sum[l-1]<=m)ans=max(ans,(ll)(r-l+1));
	}
	cout<<ans;
	return 0;
} // 5 5 1 2 4 8 9
// 5 8 -3 -1 2 2 7
