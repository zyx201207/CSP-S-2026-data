#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;long long m,a[N],sum[N];
bool chk(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-(sum[i]-sum[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	system("fc crystal4.ans crystal.out");return 0; 
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(chk(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
} 
