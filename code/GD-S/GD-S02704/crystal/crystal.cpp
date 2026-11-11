#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int n,m,a[N],b[N],l,r,ans1,ans,sum,sum1,y;
bool flag;
bool work(int xx,int mid){
	sum1=b[xx]-b[mid-1];
	if (sum-sum1<=m) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for (int i=1;i<=n;i++){
		l=1,r=i;
		while (l<=r){
			int mid=(l+r)/2;
			sum=a[i]*(i-mid+1);
			if (work(i,mid)){
				ans1=max(ans1,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans1;
	return 0;
}
