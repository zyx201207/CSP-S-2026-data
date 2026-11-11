#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=5e5+10;
long long a[N];
bool check(int x){
	long long minn=1e18+1;
	long long now=0;
	int id=0;
	long long k77=0;
	for(int i=2;i<=n;i++){
		if(i==2) k77=a[i]-a[i-1],id=i;
		if(i<=x) now+=a[i]-a[i-1];
		else{
			minn=min(minn,now);
			now+=(x-1)*(a[i]-a[i-1]);
			now-=k77;
			id++;
			k77=a[id]-a[id-1];
		}
	}
	if(minn<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); 
	int l=1,r=n;//二分答案找最大值 
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}




