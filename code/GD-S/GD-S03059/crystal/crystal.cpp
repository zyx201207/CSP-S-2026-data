#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#define endl '\n'
using namespace std;
using ll=long long;
const int MAXN=500005;
int n;
ll m,A[MAXN],sum[MAXN];
ll getval(int p,int i){
	return A[i]*(i-p)-(sum[i-1]-sum[p-1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+A[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,pos=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(getval(mid,i)<=m) pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<endl;
	return 0;
}
