#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
#define int long long
const int N=5e5+10;
int a[N];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=i;j++){
			sum+=a[i]-a[j];
		}
		if(sum>m){
			cout<<i-1<<"\n";
			return;
		}
	}
	cout<<n<<"\n";
	return;
}