#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
const long long inf=1e12+10; 
int n,m;  
long long a[N],b[N],c[N]; 
long long ans=-inf; 
bool check(int x,int i) {
	if((c[x]-c[i]-b[i]*(x-i))<=m) return true; 
	else return false; 
}
void solve() {
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i],a[i]+=inf; 
	sort(a+1,a+n+1,greater<int>()); 
	
	for(int i=2;i<=n;i++) b[i]=a[i-1]-a[i]; 
	for(int i=1;i<=n;i++) b[i]+=b[i-1]; 
	for(int i=1;i<=n;i++) c[i]=c[i-1]+b[i]; 
	
//	for(int i=1;i<=n;i++) cout<<c[i]<<" "; 
//	for(int i=1;i<=n;i++) cout<<b[i]<<" "; 
	
	for(int i=1;i<=n;i++) {
		int l=i,r=n; 
		while(true) {
			if(l>=r&&check(r,i)) break; 
			else if(l>=r) {
				r-=1; 
				break;
			}
			int mid=(l+r-1)/2; 
			if((c[mid]-c[i]-b[i]*(mid-i))<m) {
				l=mid+1; 
			}
			else r=mid; 
		}
		long long zb=r-i+1; 
		ans=max(ans,zb); 
	}
	cout<<ans<<endl; 
}
int main() {
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	solve(); 
}
