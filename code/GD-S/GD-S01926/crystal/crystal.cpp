#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
long long a[N]; 
long long n;
long long m;
long long res[N];
bool check(int mid,int k){
	int len=k-mid+1;
	long long ret=res[k]-res[mid-1];
	return len*a[k]-ret<=m;
}

void solve(){
	long long s=0;
	for(int i=1;i<=n;i++){
		int L=1,R=i;
		long long ans=0;
		while(L<=R){
			int mid=(L+R)/2;
			if(check(mid,i)){
				ans=mid;
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		s=max(s,i-ans+1);
	} 
	cout<<s<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		res[i]=res[i-1]+a[i];
	} 
	solve();
	return 0;
}

