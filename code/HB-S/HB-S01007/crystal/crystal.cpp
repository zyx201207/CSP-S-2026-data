#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long m,sum;
int ans,n,cnt;
long long a[N],q[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1;
	for(int r=1;r<=n;r++){
		sum=sum+cnt*(a[r]-a[r-1]);
		cnt++;
		while(sum>m){
			sum=sum-a[r]+a[l];
			l++;
			cnt--;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
