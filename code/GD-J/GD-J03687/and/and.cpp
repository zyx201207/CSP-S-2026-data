#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	int x=n-m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for(int i=2;i<=n;i++){
		if(m<=1) break;
		if(x && int(ans & a[i])==0){
			x--;
			continue;
		} 
		ans&=a[i];
		m--;
	}
	cout<<ans;
	return 0;
}
//数值越大，每个位数的1的可能性也就越大，and的可能性也就越大 
