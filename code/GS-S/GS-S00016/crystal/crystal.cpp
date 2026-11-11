#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int sum[N];
void solve(){
	int x=(sqrt(1+8*m)-1)/2;
	cout<<x+1;
}
void solve2(int a){
	int x=(sqrt(a*a+8*a*m)-a)/(2*a);
	cout<<x+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f1=true,f2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f1=false;
		}
	}
	int last=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=last){
			f2=false;
		}
	}
	if(f1){
		solve();
		return 0;
	}
	if(f2){
		solve2(last);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i+1;j<=n;j++){
			cnt+=(a[j]-a[j-1])*(j-1);
			if(cnt>m){
				sum[i]=j-1;
				break;
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum[i]);
	}cout<<ans;
	return 0;
}
