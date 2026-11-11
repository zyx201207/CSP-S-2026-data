#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
long long n,m,a[N],maxn;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=n;i>=1;i--){
		ans=1;
		long long y=m;
		long long x=i-1;
		while(x!=0){
			if(y-(a[i]-a[x])>=0){
				y=y-(a[i]-a[x]);
				ans++;
			}
			else break;
			x--;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0) ,cin.tie(0),cout.tie(0);
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}
