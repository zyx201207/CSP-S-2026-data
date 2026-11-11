#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,m;
int a[N];
int check(int x){
	int cnt=0;
	for(int i=1;i<=x;i++) cnt+=a[x]-a[i];
	if(cnt<=m) return 1;
	for(int i=x+1;i<=n;i++){
		cnt=cnt+(a[i]-a[i-1])*(x-1)-(a[i-1]-a[i-x]);
		if(cnt<=m) return 1;
	}
	return 0;
}
int b_s(){
	int head=1,tail=n,mid,ans=-1;
	while(head<=tail){
		mid=(head+tail)/2;
		if(check(mid)){
			head=mid+1,ans=mid;
		}else tail=mid-1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<b_s();
	return 0;
} 
