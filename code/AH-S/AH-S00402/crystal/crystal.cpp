#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans,mn=0x3f3f3f3f3f3f3f3f,sum[N];
bool check(int x){
	mn=0x3f3f3f3f3f3f3f3f;
	for(int i=x;i<=n;i++){
		int tmp=sum[i]-sum[i-x];
		mn=min(mn,(x*a[i]-tmp));
	}
	//cout<<mn<<"\n\n";
	return mn<=m;
}
int bs1(){
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	cout<<bs1();
	return 0;
}
