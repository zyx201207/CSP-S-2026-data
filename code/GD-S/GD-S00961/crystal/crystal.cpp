#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define LL long long

const int N=5e5+5;

LL n,m,ans;
LL A[N],B[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned LL rp=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++){
		B[i]=B[i-1]+A[i];
	}
	for(int i=1;i<=n;i++){
		LL L=0,R=i,mid;
		while(L<R-1){
			mid=(L+R)/2;
			if((i-mid+1)*A[i]-(B[i]-B[mid-1])<=m)R=mid;
			else L=mid;
		}
		ans=max(ans,i-R+1);
	}
	cout<<ans<<'\n';
	return 0;
}
