#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
typedef long long ll;
int n; 
ll m,a[N];
inline bool check(int x){
	ll s=0;
	for(int i=1;i<x;i++) s+=a[i];
	for(int i=x;i<=n;i++){
		s+=a[i];
		s-=a[i-x];
		if(x*a[i]-s<=m) return true;
	}
	return false;
}
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
	int L=1,R=n;
	while(L<R){
		int mid=L+R+1>>1;
		if(check(mid)) L=mid;
		else R=mid-1;
	}
	cout<<L;
	return 0;
} 
