#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
lld a[500100];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l=1,ans=1;
	lld m,s=0;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 2; i <= n; i++){
		s += (a[i]-a[i-1])*(i-l);
		while(s > m){
			s -= a[i]-a[l++];
		}
		ans = max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}