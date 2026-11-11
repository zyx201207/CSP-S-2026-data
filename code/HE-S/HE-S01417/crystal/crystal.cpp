#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
long long m;
int n;
bool check(long long mid,int i){
	return m>=(long long)((mid+1-i)*a[mid]-sum[mid]+sum[i-1]);
}
int two_fen(int i){
	int l=i,r=n;
	int ans=-1;
	long long mid=(l+r)>>1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid,i)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans-i+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=-1;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,two_fen(i));
	}
	cout<<maxn;
}
