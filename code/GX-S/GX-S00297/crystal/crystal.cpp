#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],sum,ans,cnt,mid;
long long xy(int x,int k){
	int l=1,r=x;
	//cout<<"x:"<<x<<" ";
	while(l<=r){
		mid=(l+r)/2;
		//cout<<1;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		//cout<<l<<" "<<r<<" "<<mid;
		sum=k*(x-mid+1)-(b[x]-b[mid-1]);
		if(sum>=m){
			l=mid+1;
			cnt=max(cnt,x-mid+1);
		}
		else r=mid-1;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=2;i<=n;i++){
		ans=max(ans,xy(i,a[i]));
	}
	cout<<ans;
	return 0;
}
