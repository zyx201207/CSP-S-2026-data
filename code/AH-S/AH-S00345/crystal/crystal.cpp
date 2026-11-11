#include<bits/stdc++.h>
using namespace std;
long long n, m, a[2014514], ans, h[2014514], cnt;
bool check(long long x, long long y){
	if(h[y]-h[x-1]+m>=a[y]*(y-x+1)){
		return true;
	}
	return false;
}
void output(){
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
         cin>>a[i];
     }
     sort(a+1, a+1+n);
     for(int i=1;i<=n;i++){
		 h[i]=h[i-1]+a[i];
	 }
     for(int i=1;i<=n;i++){
		long long l=1, r=i;
		cnt=i;
		while(l<=r){
			long long mid=(l+r)/2;
			if(check(mid, i)){
				r=mid-1;
				cnt=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans, i-cnt+1);
	 }
	 cout<<ans;
}
